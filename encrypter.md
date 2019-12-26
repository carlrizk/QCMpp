# Encrypter
Encrypter class using Ceaser Cypher.

### Constructors:
``` cpp
Encrypter();
Encrypter(int shift);
```

### Methods:
> ```cpp
> void encrypt(string & source);
> ```
> Encrypts and modifies ```source```

> ```cpp
> void decrypt(string & source);
> ```
> Decrypts and modifies ```source```


### Examples:
```cpp
Encrypter e;
string s = "abc";
e.encrypt(s);
cout << s << endl;    // "def"
e.decrypt(s);
cout << s << endl;    // "abc"
```
