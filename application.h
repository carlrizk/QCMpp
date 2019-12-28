#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <string>
#include <unordered_map>
#include <memory>

#include "mcq.h"
#include "user.h"

namespace QCMpp {

class Application : public QObject
{

    Q_OBJECT

public:
    Application(const std::string & configuration_path);

    ~Application();

public slots:
    //Example void addUser(string, string) check if username and password valid and add them to the map

signals:

private:
    std::vector<std::unique_ptr<MCQ>> mcqs;
    std::unordered_map<std::string, std::unique_ptr<User>> users;

};
}
#endif // APPLICATION_H
