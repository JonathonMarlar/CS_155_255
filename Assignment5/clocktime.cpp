#include "clocktime.h"
#include <iostream>

const int TIMEFORMAT = 12;
const int MINPERHOUR = 60;
const int SECPERMIN = 60;

clocktime::clocktime() : h(0), m(0), s(0) {}

clocktime::clocktime(unsigned short hx, unsigned short mx, unsigned short sx){

  h=0;
  m=0;
  s=0;

  if ((hx > 0) && (hx < TIMEFORMAT+1))
    h = hx;

  if ((mx > 0) && (mx < MINPERHOUR+1))
    m = mx;

  if ((sx > 0) && (sx < SECPERMIN+1))
    s = sx;
}


void clocktime::setTime(unsigned short hx, unsigned short mx, unsigned short sx){
 if ((hx > 0) && (hx < TIMEFORMAT+1))
    h = hx;

  if ((mx > 0) && (mx < MINPERHOUR+1))
    m = mx;

  if ((sx > 0) && (sx < SECPERMIN+1))
    s = sx;
}

int clocktime::getHour() const { return h;}

int clocktime::getMin() const { return m;}

int clocktime::getSec() const { return s;}

void clocktime::displayTime() const {

     using namespace std;

     cout.fill('0');
     cout.width(2);
     cout << h << ":";

     cout.fill('0');
     cout.width(2);
     cout << m << ":";

     cout.fill('0');
     cout.width(2);
     cout << s << endl;
}

bool operator ==(const clocktime & tm1, const clocktime & tm2){

  return (
              ( tm1.getHour() == tm2.getHour() ) &&
              ( tm1.getMin() == tm2.getMin() ) &&
              ( tm1.getSec() == tm2.getSec() )
         );

}

/////////////////////////// MY CODE //////////////////////////////////

const clocktime operator +(const clocktime & tm1, const clocktime & tm2) {
	int h3, m3, s3;

	h3 = tm1.getHour() + tm2.getHour();
	if ( h3 > TIMEFORMAT )
		h3 -= TIMEFORMAT;

	m3 = tm1.getMin() + tm2.getMin();
	if ( m3 > MINPERHOUR )
		m3 -= MINPERHOUR;

	s3 = tm1.getSec() + tm2.getSec();
	if ( s3 > SECPERMIN )
		s3 -= MINPERHOUR;

    clocktime tm3(h3, m3, s3);
    return tm3;
}

const clocktime operator -(const clocktime & tm1, const clocktime & tm2) {
	int h3, m3, s3;

	h3 = tm1.getHour() - tm2.getHour();
	if ( h3 <= 0 )
		h3 += TIMEFORMAT;

	m3 = tm1.getMin() - tm2.getMin();
	if ( m3 < 0 )
		m3 += MINPERHOUR;

	s3 = tm1.getSec() - tm2.getSec();
	if ( s3 < 0 )
		s3 += MINPERHOUR;

    clocktime tm3(h3, m3, s3);
    return tm3;
}
