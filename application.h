#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <string>

namespace QCMpp {

class Application : public QObject
{

    Q_OBJECT

public:
    Application(const std::string & configuration_path);

    ~Application();

public slots:

signals:

private:


};
}
#endif // APPLICATION_H
