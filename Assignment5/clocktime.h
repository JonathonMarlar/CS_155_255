#ifndef CLOCKTIME_H
#define CLOCKTIME_H

class clocktime {
      public:
             clocktime();
             clocktime(unsigned short h, unsigned short m, unsigned short s);

             void setTime(unsigned short h, unsigned short m, unsigned short s);
             int getHour() const;
             int getMin() const;
             int getSec() const;
             void displayTime() const;

      private:
              unsigned short h;
              unsigned short m;
              unsigned short s;
};

bool operator ==(const clocktime & tm1, const clocktime & tm2);

////////////////////////////////////////////////////////////////////////////

const clocktime operator +(const clocktime & tm1, const clocktime & tm2);

const clocktime operator -(const clocktime & tm1, const clocktime & tm2);

#endif
