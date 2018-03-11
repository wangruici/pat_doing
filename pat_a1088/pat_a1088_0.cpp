#include <cstdio>
#include <algorithm>

using std::abs;
typedef long long ll;

struct Fraction{
	ll up;
	ll down;
	bool InfFlag;
	Fraction(ll up,ll down){
		this->up=up;
		this->down=down;
		this->InfFlag=false;
		if(down==0){
			this->InfFlag=true;
		}
	}
	Fraction()=default;
	Fraction(const Fraction &f){
		this->up=f.up;
		this->down=f.down;
		this->InfFlag=f.InfFlag;
	}
};

//辗转相除法求余数
ll sdm(ll a,ll b){
	if(b==0) return a;
	ll c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
//化为标准型
Fraction& reduction(Fraction &f){
	//化为标准型
	if(f.InfFlag==true){
		f.up=0;
		f.down=0;
	}
	else if(f.down<0){
		f.up=-f.up;
		f.down=-f.down;
	}
	else if(f.up<0&&f.down<0){
		f.up=-f.up;
		f.down=-f.down;
	}
	else if(f.up==0){
		f.down=1;
	}
	else{
		ll d=sdm(abs(f.up),abs(f.down));
		f.up=f.up/d;
		f.down=f.down/d;
	}
	return f;
}

Fraction
operator +(const Fraction &f1,const Fraction &f2){
	Fraction result;
	if(f1.InfFlag==true||f2.InfFlag==true){
		result.up=result.down=0;
		result.InfFlag=true;
	}
	else{
		result.up=f1.up*f2.down+f2.up*f1.down;
		result.down=f1.down*f2.down;
		result.InfFlag=false;
		reduction(result);
	}
	return result;
}


Fraction
operator -(const Fraction &f1,const Fraction &f2){
	Fraction f3(-f2.up,f2.down);
	Fraction f=f1+f3;
	return f;
}

Fraction
operator *(const Fraction &f1,const Fraction &f2){
	Fraction result;
	if(f1.InfFlag==true||f2.InfFlag==true){
		result.up=result.down=0;
		result.InfFlag=true;
	}
	else{
		result.up=f1.up*f2.up;
		result.down=f1.down*f2.down;
		result.InfFlag=false;
		reduction(result);
	}
	return result;
}

Fraction
operator /(const Fraction &f1,const Fraction &f2){
	Fraction f3(f2.down,f2.up);
	return f1*f3;
}

void print_fraction(Fraction &f){
	reduction(f);
	if(f.InfFlag){
		printf("Inf");
	}
	else{
		ll d=f.up/f.down;
		if(f.down==1){
			if(f.up<0){
				printf("(%lld)",f.up);
			}
			else{
				printf("%lld",f.up);
			}
		}
		else{
			if(d!=0){
				if(f.up<0){
					printf("(-%lld %lld/%lld)",abs(d),abs(f.up)%abs(f.down),abs(f.down));
				}
				else{
					printf("%lld %lld/%lld",abs(d),abs(f.up)%abs(f.down),abs(f.down));
				}
			}
			else{
				if(f.up<0){
					printf("(-%lld/%lld)",abs(f.up),abs(f.down));
				}
				else{
					printf("%lld/%lld",abs(f.up),abs(f.down));
				}
			}
		}
	}
}

int main(){
	ll up1,down1,up2,down2;
	scanf("%lld/%lld %lld/%lld",&up1,&down1,&up2,&down2);
	Fraction f1(up1,down1),f2(up2,down2);
	//+
	Fraction f=f1+f2;
	print_fraction(f1);printf(" + ");print_fraction(f2);printf(" = ");print_fraction(f);
	printf("\n");
	//-
	f=f1-f2;
	print_fraction(f1);printf(" - ");print_fraction(f2);printf(" = ");print_fraction(f);
	printf("\n");
	//*
	f=f1*f2;
	print_fraction(f1);printf(" * ");print_fraction(f2);printf(" = ");print_fraction(f);
	printf("\n");
	///
	f=f1/f2;
	print_fraction(f1);printf(" / ");print_fraction(f2);printf(" = ");print_fraction(f);
	printf("\n");
	return 0;
}


