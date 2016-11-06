#include "../header/erros.h"

erros::erros(){

}

double erros::erroAbs(double xa, x){
	return abs(xa - x);
}

double erros::erroRel(double xa, x){
	return abs(xa - x)/abs(x);
}