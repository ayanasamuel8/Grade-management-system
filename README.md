# 🎓 Pre-Engineering Grade Management System (C++)

This is a **console-based C++ application** designed to help **teachers manage student assessments** and allow **students to check their grades** using their ID number.

---

## 📌 Features

### 👩‍🏫 Teacher Functionality
- 🔐 **Sign Up & Login** with name and password
- 📚 Add new students and their assessments (assessment + final)
- 💾 Store student information in `.csv` files (named after the teacher)
- 📝 Choose to either:
  - Overwrite existing records
  - Append to existing records
- 📊 Auto-grade based on total score (assessment + final)

### 👨‍🎓 Student Functionality
- 🔍 Enter student ID to view:
  - Subject
  - Assessment score
  - Final score
  - Computed grade

---

## 🛠️ Technologies Used

- 📦 **C++** — Core language for logic & file operations
- 📂 **File Handling** — Student data and teacher credentials stored in `.csv` format
- 📄 **Linked List (ADT)** — To manage students in memory before writing to file

---

## 📐 Grading System

| Score Range | Grade |
|-------------|-------|
| 90+         | A+    |
| 85–89       | A     |
| 80–84       | A−    |
| 75–79       | B+    |
| 70–74       | B     |
| 65–69       | B−    |
| 60–64       | C+    |
| 50–59       | C     |
| 45–49       | C−    |
| 40–44       | D     |
| < 40        | F     |

---

## 🚀 How to Run

1. **Clone or Download** this repository.
2. Open the project in a C++ IDE (like Code::Blocks, Dev C++, or VS Code with C++ extensions).
3. Compile and run the project.
4. Follow the on-screen instructions:
   - Choose Teacher or Student
   - Enter credentials
   - Manage or view grades

---

## 🧠 Notes

- Teacher login credentials are saved to `sign.csv`
- Each teacher’s student data is saved to a file named after their lowercase username (e.g., `john.csv`)
- Application enforces:
  - Valid login for teachers
  - ID match for students
- File input/output is used instead of a database to keep it lightweight

---

## 🙋‍♂️ Author

**Ayana Samuel**  
Computer Science & Engineering Student, ASTU 🇪🇹  
📧 ayanasamuel8@gmail.com  
🔗 [GitHub Profile](https://github.com/ayanasamuel8)

---

## 📄 License

This project is licensed for educational use and personal learning. Feel free to modify or extend it!

