#include <iostream>
using namespace std;

struct Student {
    int sNo;
    Student* next;
};

struct Course {
    int cNo;
    Course* next;
};

struct Link {
    Student* student;
    Course* course;
    Link* next;
};

Student* studentHead = NULL;
Course* courseHead = NULL;
Link* linkHead = NULL;

void addCourse(int cNo) {
    Course* newCourse = new Course;
    newCourse->cNo = cNo;
    newCourse->next = courseHead;
    courseHead = newCourse;
    cout << "Course added\n";
}

Course* searchCourse(int cNo) {
    Course* temp = courseHead;
    while (temp != NULL) {
        if (temp->cNo == cNo)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void displayCourses() {
    Course* temp = courseHead;
    if (temp == NULL) {
        cout << "No courses available\n";
        return;
    }
    cout << "Courses: ";
    while (temp != NULL) {
        cout << temp->cNo << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addStudentToCourse(int sNo, int cNo) {
    Course* c = searchCourse(cNo);
    if (c == NULL) {
        cout << "Course not found\n";
        return;
    }

    Student* s = studentHead;
    while (s != NULL && s->sNo != sNo) {
        s = s->next;
    }

    if (s == NULL) {
        s = new Student;
        s->sNo = sNo;
        s->next = studentHead;
        studentHead = s;
    }

    Link* l = new Link;
    l->student = s;
    l->course = c;
    l->next = linkHead;
    linkHead = l;

    cout << "Student added to course\n";
}

void displayAll() {
    Course* c = courseHead;
    while (c != NULL) {
        cout << "Course " << c->cNo << ": ";
        Link* l = linkHead;
        int found = 0;
        while (l != NULL) {
            if (l->course == c) {
                cout << l->student->sNo << " ";
                found = 1;
            }
            l = l->next;
        }
        if (!found)
            cout << "No students";
        cout << endl;
        c = c->next;
    }
}

void deleteCourse(int cNo) {
    Course* curr = courseHead;
    Course* prev = NULL;

    while (curr != NULL && curr->cNo != cNo) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Course not found\n";
        return;
    }

    if (prev == NULL)
        courseHead = curr->next;
    else
        prev->next = curr->next;

    Link* l = linkHead;
    Link* pl = NULL;

    while (l != NULL) {
        if (l->course == curr) {
            if (pl == NULL)
                linkHead = l->next;
            else
                pl->next = l->next;

            Link* del = l;
            l = l->next;
            delete del;
        } else {
            pl = l;
            l = l->next;
        }
    }

    delete curr;
    cout << "Course deleted\n";
}

int main() {
    int choice, cNo, sNo;

    do {
        cout << "\n1. Add Course";
        cout << "\n2. Search Course";
        cout << "\n3. Display Course List";
        cout << "\n4. Add Student to Course";
        cout << "\n5. Display All";
        cout << "\n6. Delete Course";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Course No: ";
            cin >> cNo;
            addCourse(cNo);
        }
        else if (choice == 2) {
            cout << "Enter Course No: ";
            cin >> cNo;
            if (searchCourse(cNo))
                cout << "Course found\n";
            else
                cout << "Course not found\n";
        }
        else if (choice == 3) {
            displayCourses();
        }
        else if (choice == 4) {
            cout << "Enter Student No: ";
            cin >> sNo;
            cout << "Enter Course No: ";
            cin >> cNo;
            addStudentToCourse(sNo, cNo);
        }
        else if (choice == 5) {
            displayAll();
        }
        else if (choice == 6) {
            cout << "Enter Course No: ";
            cin >> cNo;
            deleteCourse(cNo);
        }

    } while (choice != 0);

    return 0;
}
