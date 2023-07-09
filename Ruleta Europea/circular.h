
typedef struct Nodo{
      Elem dato;
      struct Nodo *sig;
}*Circular;



int esnuevaC(Circular c){return c==NULL;}
Circular nuevaC(){return NULL;}
Circular formarC(Circular c, Elem e){
    Circular t=(Circular)malloc(sizeof(struct Nodo));
    t->dato=e;
        if(esnuevaC(c)){
            c=t; t->sig=t;
        }else{
            t->sig=c->sig;
            c->sig=t;
            c=t;
        }
      return c;
}
Elem primeroC(Circular c){ return c->sig->dato;}
Circular desformarC(Circular c){
     if(c==c->sig)
        return nuevaC();
     else{
          c->sig=c->sig->sig;
          return c;
     }
}
Circular rotar(Circular c){return c=c->sig;}
