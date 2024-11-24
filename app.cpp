#include "app.h"
#include "course.h"
#include "dashboard.h"
#include "event.h"
#include "admin.h"
#include "student.h"
#include "utils.h"
#include <QMessageBox>
#include <QRegularExpression>

App::App() {
    // Load data when the app starts
    course_repository = new  CourseRepository();
    course_repository->load();
    event_repository = new EventRepository();
    event_repository->load();
    auth_repository = new AuthenticationRepository();
    event_manager =  new EventManager(*this);
    course_manager = new CourseManager(*this);
    auth_manager = new AuthManager(*this);
}
App::CourseManager::CourseManager(App &app) : app(app) {}
App::EventManager::EventManager(App &app) : app(app ) {}
App::AuthManager::AuthManager(App &app) : app(app) {}

App::~App() {
    // Save data before closing the app
    course_repository->store();
    event_repository->store();
    delete course_repository;
    delete event_repository;
    delete auth_repository;
    delete course_manager;
    delete event_manager;
    delete auth_manager;
}

// CRUD operations for events
void App::EventManager::create(Event* event){
    app.event_repository->add(event);
}

void App::EventManager::update(Event* event){
    app.event_repository->update(event);
}

void App::EventManager::remove(Event* event){
    app.event_repository->remove(event);
}

Event* App::EventManager::get(QUuid id){
    return dynamic_cast<Event*>(app.event_repository->get(id));
}

QList<Event*> App::EventManager::get_all(){
    QList<Event*> result;
    for (auto event : app.event_repository->get_all()){
        auto* e = dynamic_cast<Event*>(event);
        if (e != nullptr){
            result.append(e);
        }
    }
    return result;
}

// Crud Operations for courses

void App::CourseManager::create(Course* course){
    app.course_repository->add(course);
}

void App::CourseManager::update(Course* course){
    app.course_repository->update(course);
}

void App::CourseManager::remove(Course* course){
    app.course_repository->remove(course);
}

Course* App::CourseManager::get(QUuid id ) {
    return dynamic_cast<Course*>(app.course_repository->get(id));
}

QList<Course*> App::CourseManager::get_all() {
    QList<Course*> result ;
    for ( auto course : app.event_repository->get_all()){
        auto* c = dynamic_cast<Course*>(course);
        if ( c != nullptr){
            result.append(c);
        }
    }
    return result ;
}

// AuthManager

void App::AuthManager::login(QString username, QString password){
    try {
        if (username.isEmpty() || password.isEmpty()){
            QMessageBox::warning(app.current_window, "Error", "All fields are required");
            return;
        }
        app.auth_repository->login(username, password);
        app.current_window->hide();
        app.current_window = new Dashboard();
        app.current_window->show();

    } catch (std::exception &e){
        QMessageBox::warning(app.current_window, "Error", e.what());
    }
}

void App::AuthManager::signup(QString id, QString username, QString password, QString firstname, QString lastname, QString email, QString phone, QString type){

    if (id.isEmpty() || username.isEmpty() || password.isEmpty() || firstname.isEmpty() || lastname.isEmpty() || email.isEmpty() || phone.isEmpty()){
        QMessageBox::warning(app.current_window, "Error", "All fields are required");
        return;
    }

    if (!Email::is_valid_email(email)) {
        QMessageBox::warning(app.current_window, "Error", "Invalid email address");
        return;
    }

    // check if phone has anything other than numbers
    if (!phone.contains(QRegularExpression(("[0-9]+")))) {
        QMessageBox::warning(app.current_window, "Error", "Invalid phone number");
        return;
    }

    // check if id has anything other than numbers
    if (id.length() != 8 || !id.contains(QRegularExpression("^[0-9]*$"))) {
        QMessageBox::warning(app.current_window, "Error", "Invalid id");
        return;
    }

    User *newUser;
    try {
        if (type == "Student") {
            // Create a new student
            newUser = new class Student(
                id, username, password, firstname, lastname, email, phone, 0.0, ClassStanding::Freshman
                );
        } else {
            // Create a new admin
            newUser = new class Admin(
                id, username, password, firstname, lastname, email, phone, AdminRole::Instructor, 3000
                );
        }
        app.auth_repository->signup(newUser);
        app.current_window->hide();
        delete app.current_window;

        app.current_window = new Dashboard();
        app.current_window->show();


    } catch(std::exception &e){
        // Notify user
        QMessageBox::warning(app.current_window, "Error", e.what());
    }
}

void App::AuthManager::logout(){
    try {
        app.auth_repository->logout();
        app.current_window->close();
        delete app.current_window;
    } catch (std::exception &e){
        QMessageBox::warning(app.current_window, "Error", e.what());
        return;
    }

}

void App::set_current_window(QWidget *window){
    current_window = window;
}

QWidget *App::get_current_window(){
    return current_window;
}
