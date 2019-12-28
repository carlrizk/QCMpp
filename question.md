# Question
Question Class

### Constructors:
```cpp
Question(const std::string& text);
Question(const Question& q);
```

### Methods:
>```cpp
>void add_answer(const Answer & a);
>```
>Adds an answer to a question

>```cpp
>bool correct(const std::vector<bool> u_Answers) const;
>```
>Corrects the user's answers, returns true if his choices are correct and false otherwise

### Examples:
```cpp
Question q1("1+1=?");
Answer a1("2",true);
Answer a2("3",false);
q1.add_answer(a1);
q1.add_answer(a2);
q1.correct({1,1});      //false
q1.correct({1,0});      //true
```
