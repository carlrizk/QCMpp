# MCQ
Mutliple Choice Questions Class

### Constructor:
```cpp
MCQ(const std::string & title);
```

### Methods:
>```cpp
>void add_question(const Question & q);
>```
>Adds a question to the MCQ

>```cpp
>int correct(const std::vector<const std::vector<bool>> & u_Answers) const;
>```
>Checks if the user's answers to the MCQ are correct

>```cpp
>void add_grade(const Student & s, int grade);
>```
>Adds a student's grade

### Examples:
```cpp
MCQ mcq1("MCQ1");

Question q1("Q1:");
Answer a1("Answer 1",true);
Answer a2("Answer 2",false);
q1.add_answer(a1);
q1.add_answer(a2);

Question q2("Q2:");
Answer a3("Answer 1",false);
Answer a4("Answer 2",true);
q2.add_answer(a3);
q1.add_answer(a4);

Student s1("my_username","my_encrypted_password");

mcq1.add_question(q1);
mcq2.add_question(q2);
int grade = mcq1({{0,1},{1,0});  //grade = 0
mcq1.add_grade(s1,grade);
```
