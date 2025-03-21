#include <iostream>

using	namespace	std;

int	soma_a(int	a,	int	b){
	int	c;
	c=a+b;
	return	c;
}

int	soma_v(int	vet[],int N){
	int	s=0;
	for(int	i=0;i<N;i++){
		s+=vet[i];
	}
	return	s;
}

struct	maxpos{
	int	max;
	int	pos;
};

int	main(){
	char a;
	int	b;//1 byte
	short	c;//4 bytes
	long	d;//2 bytes
	float	e;//8 bytes
	string	f="ufsc";//4 bytes
	char	g[100]="FLo";

	cout<<"a";

	int	h[5]={30,20,50,10,40};
	printf("%p\n",h);//h é o ponteiro para o inicio do vtor
	cout<<"*h= "<<*h<<endl;
	cout<<"h[3]= " << h[3]<<endl;
	cout<< "*(h+3) "<<*(h+3)<<endl;
	
	int	*p;	//declaracao de ponteiro
	p=h;
	cout<<"*(p+4)"<<*(p+4)<<endl;

	float	v[10];

	int	i;
	for(i=0;i<10;i++){
		v[i]=0.0;
	}
	
	for(int	i=0;	i<10;	i++){
		cout	<<	v[i]	<<	' ';
	}
	cout<<endl;

	i=0;
	while(i<10){
		v[i]=0.0;
		if(i>=5){
			v[i]=1.0;
		}else{
			v[i]=0.0;
		}
		i++;
	}

	i=0;
	do{
		v[i]=0;	
	}while(i<10);

	int	op=1;
	switch(op){
		case	1:
			cout<<'a';
			break;
		case	2:
			cout<<'b';
			break;
		default:
			cout<<"default";
	}
	cout<<endl;

	int	x=3,	y=5,	z;
	z=soma_a(x,y);
	cout<<"z = "<<z<<endl;

	int	vet[5]={3,9,4,1,2};
	z=soma_v(vet,5);

	maxpos	minha_var;
	minha_var.max=0;
	minha_var.pos=0;
	cout<<minha_var.max<<endl;
	cout<<minha_var.pos<<endl;


	return	0;
}
