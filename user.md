# User (abstract)
User class

### Constructors:
``` cpp
User(const std::string & username,const std::string & password, bool admin = false);
```

### Methods:
> ```cpp
> virtual bool isAdmin() const = 0;
> ```
> Returns ```true``` if ```Admin```, ```false``` if ```Student```.

> ```cpp
> void setAdmin(bool admin);
> ```
> Set ```admin``` to ```true``` or ```false```.


> ```cpp
> std::string getUsername() const;
> ```
> Returns ```username```.

> ```cpp
> bool matchPassword(const std::string & pass);
> ```
> Returns ```true``` if ```pass``` matches ```password```.
