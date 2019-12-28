# Answer 
Answer class

### Constructor:
``` cpp
Answer(const std::string & text, const bool correct);
```

### Methods:
> ``` cpp
>bool isCorrect() const;
>```
>Indicates if this answer is correct or not

### Examples:
``` cpp
Answer a("First Choice",true);
bool correct = a.isCorrect();     //correct=true
```
