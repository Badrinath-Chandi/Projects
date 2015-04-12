#include<iostream>
#include <string.h>

using namespace std;

#if 0
/* Adapter DP*/
class plug {
	char spec[100];
public:
	plug() {
		strcpy_s(spec, "it supports two pin socket");
	}
	void getspec() {
		cout << spec << endl;
	}
};

class socket {
	plug* p;
public:
	socket(){}

	void setPlug(plug* p) {
		this->p = p;
	}

	void getspec() {
		p->getspec();
		cout << "Now converted to 3 pin Socket" << endl;
	}
};

int main() {
	/* Client */
	plug *p = new plug();
	socket *s = new socket();
	s->setPlug(p);
	s->getspec();
	getchar();
}
#endif

#if 0
/* bridge DP */

class TV {
	
public:
	virtual void powerOn() = 0;
	virtual void powerOff() = 0;
	int curChannel;
};

class googleTV : public TV {	
public:
	googleTV() {
		curChannel = 0;
	}
	void powerOn() {
		cout << "Goole TV powering on...."<<endl;
	}
	void powerOff() {
		cout << "Google TV powering off...." << endl;
	}
};

class appleTV : public TV {	
public:
	appleTV() {
		curChannel = 0;
	}
	void powerOn() {
		cout << "Apple TV powering on...." << endl;
	}
	void powerOff() {
		cout << "Apple TV powering off...." << endl;
	}
};

class remoteController {	
public:
	TV* tv;
	remoteController(TV *tv) :tv(tv) {}
	void On() {
		tv->powerOn();
	}
	void Off() {
		tv->powerOff();
	}
	virtual int nextChannel() = 0;
	virtual int prevChannel() = 0;
	virtual int getcurChannel() = 0;
};

class refinedRController : public remoteController{
	
public:	
	refinedRController(TV *tv) : remoteController(tv) {}
	int nextChannel() {
		if (tv->curChannel < 100)
			tv->curChannel++;
		else
			tv->curChannel = 0;
		return tv->curChannel;
	}
	int prevChannel() {
		if (tv->curChannel > 0)
			tv->curChannel--;
		else
			tv->curChannel = 100;
		return tv->curChannel;
	}
	int getcurChannel() {
		return tv->curChannel;
	}
};
int main() {
	TV *gTV = new googleTV();
	remoteController *rC = new refinedRController(gTV);
	rC->On();
	cout << "cur Channel is " << rC->getcurChannel() <<endl;
	rC->nextChannel();
	cout << "cur Channel is " << rC->getcurChannel() << endl;
	rC->prevChannel();
	cout << "cur Channel is " << rC->getcurChannel() << endl;
	rC->prevChannel();
	cout << "cur Channel is " << rC->getcurChannel() << endl;
	getchar();
}
#endif

class Coffee {
	int price;
	char desc[100];
public:
	Coffee() {
		price = 100;
		strcpy_s(desc, " Normal Coffee");
	}
	virtual int getPrice() {
		return price;
	}
	virtual void getdescription() {
		cout << desc <<" ";
	}
};

class expresso : public Coffee {
	int price;
	char desc[100];
public:
	expresso() {
		price = 50;
		strcpy_s(desc, " Adding expresso seeds");
	}
	int getPrice() {
		return Coffee::getPrice() + price;
	}
	void getdescription() {
		Coffee::getdescription();
		cout << desc << endl;
	}
};