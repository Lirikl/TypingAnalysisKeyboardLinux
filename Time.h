#ifndef NSAPPLICATION_CTIME_H
#define NSAPPLICATION_CTIME_H


namespace NSApplication {


class CTime {
public:
  friend CTime operator+(const CTime& first, const CTime& second);
  friend CTime operator-(const CTime& first, const CTime& second);
  CTime& operator+=(const CTime& other);
  CTime& operator-=(const CTime& other);

  friend bool operator<(const CTime& first, const CTime& second);
  friend bool operator>(const CTime& first, const CTime& second);
  friend bool operator<=(const CTime& first, const CTime& second);
  friend bool operator>=(const CTime& first, const CTime& second);
  friend bool operator==(const CTime& first, const CTime& second);
  friend bool operator!=(const CTime& first, const CTime& second);
  CTime operator-() const;

  long long toMicroSecondsI() const;
  long long toMilliSecondsI() const;
  long long toSecondsI() const;

  double toMicroSecondsF() const;
  double toMilliSecondsF() const;
  double toSecondsF() const;

  static constexpr long long kMicrosecondsInMilliseconds = 1000;
  static constexpr long long kMicrosecondsInSeconds = 1000000;
  static constexpr long long kMillisecondsInSeconds = 1000;

protected:
  CTime(long long microseconds);
  long long Microseconds_ = 0;
};

class MicroSeconds : public CTime {
public:
  MicroSeconds(long long microseconds);
};

class MilliSeconds : public CTime {
public:
  MilliSeconds(long long milliseconds);
};

class Seconds : public CTime {
public:
  Seconds(long long seconds);
};

} // NSApplication

#endif // NSAPPLICATION_CTIME_H