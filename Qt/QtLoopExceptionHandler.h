#ifndef NSAPPLICATION_NSQT_CQTLOOPEXCEPTIONHANDLER_H
#define NSAPPLICATION_NSQT_CQTLOOPEXCEPTIONHANDLER_H

#include <stdexcept>
#include <QObject>


namespace NSApplication {
namespace NSQt {

class CQtException : public std::runtime_error {
  using CBase = std::runtime_error;
  using CBase::CBase;
public:
  CQtException() : CBase("") {}
};

class CQtLoopExceptionHandler : public QObject {
  Q_OBJECT
public:
  CQtLoopExceptionHandler();
  template<class TO, class TS>
  void connectSignal(TO* obj, TS&& signal) {
    connect(obj, std::forward<TS>(signal), this, &CQtLoopExceptionHandler::handleException);
  }
signals:
  void quit();
public slots:
  void handleException(const CQtException&);
};

} // NSQt
} // NSApplication

// This macro is required to use the CQtException class in Qt message system
Q_DECLARE_METATYPE(NSApplication::NSQt::CQtException);

#endif // NSAPPLICATION_NSQT_CQTLOOPEXCEPTIONHANDLER_H
