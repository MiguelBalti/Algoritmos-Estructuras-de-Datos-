typedef struct NodoBC{ Elem dato;
                     struct NodoBC *der;   // ->
                     struct NodoBC *izq;   // <-
               }*ApNodoBC;
typedef struct BCnodo{ ApNodoBC izq;
                       ApNodoBC der;
              }*BiCola;

BiCola nuevaBC(){
   BiCola t=(BiCola)malloc(sizeof(struct BCnodo));
   t->izq=t->der=NULL;
   return t;
}

int esnuevaBC(BiCola q){ return ((q->izq==NULL)&&(q->der==NULL));}

BiCola formarDerBC(BiCola q, Elem e){
    ApNodoBC t=(ApNodoBC)malloc(sizeof(struct NodoBC));
    t->dato=e; t->der=t->izq=NULL;
    if(esnuevaBC(q))
        q->izq=q->der=t;
    else{
        q->der->der=t;
        t->izq=q->der;
        q->der=t;
        }
    return q;
}

BiCola formarIzqBC(Elem e, BiCola q){
    ApNodoBC t=(ApNodoBC)malloc(sizeof(struct NodoBC));
    t->dato=e; t->der=t->izq=NULL;
    if(esnuevaBC(q))
        q->izq=q->der=t;
    else{
        q->izq->izq=t;
        t->der=q->izq;
        q->izq=t;
        }
    return q;
}

Elem izquierdoBC(BiCola q){return q->izq->dato;}
Elem derechoBC(BiCola q){return q->der->dato;}

BiCola desformarIzqBC(BiCola q){
       ApNodoBC t;
       if(q->izq==q->der){
           free(q->izq); free(q); return nuevaBC();
       }else{
           t=q->izq;
           q->izq=q->izq->der;
           q->izq->izq=NULL;
           free(t);
           return q;
          }
}

BiCola desformarDerBC(BiCola q){
       ApNodoBC t;
       if(q->izq==q->der){
           free(q->der); free(q); return nuevaBC();
       }else{
           t=q->der;
           q->der=q->der->izq;
           q->der->der=NULL;
           free(t);
           return q;
          }
}



/*
Espec BiCola
    Constructoras:
        nuevaBC:->BiCola;
        formarIzqBC: Elem, BiCola -> BiCola;
        formarDerBC: BiCola, Elem -> BiCola;
    Observadoras:
        esnuevaBC: BiCola -> Bool;
        izquierdoBC: BiCola-> Elem;
        derechoBC: BiCola -> Elem;
    Desdobladoras:
        desformarIzqBC: BiCola -> BiCola;
        desformarDerBC: BiCola -> BiCola;

  Axiomas: Elem e, BiCola d;
     [bc1] esnuevaBC(nuevaBC())= Verdadero;
     [bc2] esnuevaBC(formarIzqBC(e,d))= Falso;
     [bc3] esnuevaBC(formarDerBC(d,e))= Falso;
     [bc4] izquierdoBC(nuevaBC())= ERROR;
     [bc5] izquierdoBC(formarIzqBC(e,d))= e;
     [bc6] izquierdoBC(formarDerBC(d,e))= Si esnuevaBC(d) ret e;
                                          Sino ret izquierdoBC(d);
     [bc7] derechoBC(nuevaBC()) = ERROR;
     [bc8] derechoBC(formarIzqBC(e,d)) =  Si esnuevaBC(d) ret e;
                                          Sino ret derechoBC(d);
     [bc9] derechoBC(formarDerBC(d,e)) = e;
     [bc10] desformarIzqBC(nuevaBC()) = ERROR;
     [bc11] desformarIzqBC(formarIzqBC(e,d)) = d;
     [bc12] desformarIzqBC(formarDerBC(d,e)) = Si esnuevaBC(d) ret d;
                                   Sino ret formarDerBC(desformarIzqBC(d),e);
     [bc13] desformarDerBC(nuevaBC()) = ERROR;
     [bc14] desformarDerBC(formarIzqBC(e,d)) = Si esnuevaBC(d) ret d;
                                   Sino ret formarIzqBC(e,desformarDerBC(d));
     [bc15] desformarDerBC(formarDerBC(d,e)) = d;
Fin BiCola.
*/
