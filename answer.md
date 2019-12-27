# Answer 
Answer class

### Constructor:
``` cpp
Answer(const std::string & texte, const bool correct);
```

### Methods:
> ``` cpp
>bool isCorrect() const;
>```
>Gets correct's value

### Examples:
``` cpp
Answer a("First Choice",true);
bool correct = a.isCorrect();     //correct=true
```
