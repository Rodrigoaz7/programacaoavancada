#ifndef _CIRCUITO_H_
#define _CIRCUITO_H_

#include <iostream>
#include <vector>
#include <QString>

using namespace std;

// Criando um tipo de dados enumerado para representar um booleano com 3 estados:
// TRUE_3S, FALSE_3S e UNDEF_3S

enum bool_3S {
  FALSE_3S = 0,
  TRUE_3S = 1,
  UNDEF_3S = -1
};

#define NUM_MAX_INPUTS_PORTA 4

class Porta;
typedef Porta *ptr_Porta;

class Porta {
protected:
  string tipo;
  unsigned Nin;
  int id_in[NUM_MAX_INPUTS_PORTA];
  bool_3S saida;
public:
  inline Porta(unsigned NI = 2): Nin(NI){saida = UNDEF_3S;}
  Porta(const Porta &P);
  inline virtual ~Porta() {}

  virtual ptr_Porta clone() const = 0;
  inline unsigned getNumInputs() const {return Nin;}
  inline bool_3S getSaida() const {return saida;}
  inline string getTipo() const {return tipo;}
  inline void setTipo(string novo_tipo){tipo = novo_tipo;}
  void setSaida(bool_3S s);
  void setNin(unsigned i);
  void setId_in(unsigned i, int N);
  int getId_in(unsigned i) const;
  unsigned getIn() {return Nin;}
  virtual void digitar();
  virtual bool ler(istream &I);
  virtual ostream &imprimir(ostream &O) const =0 ;

  virtual bool_3S simular(const bool_3S in[]) = 0;
};

// Operador << com comportamento polimorfico
inline ostream &operator<<(ostream &O, const Porta &X) {return (&X)->imprimir(O);}

class Porta_NOT: public Porta {
public:
  inline Porta_NOT(): Porta(1) {}
  inline ~Porta_NOT() {}
  inline ptr_Porta clone() const {return new Porta_NOT(*this);}

  void digitar();
  bool ler(istream &I);
  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Porta_AND: public Porta {
public:
  inline Porta_AND(): Porta() {}
  inline ~Porta_AND() {}
  inline ptr_Porta clone() const {return new Porta_AND(*this);}

  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Porta_NAND: public Porta {
public:
  inline Porta_NAND(): Porta() {}
  inline ~Porta_NAND() {}
  ptr_Porta clone() const {return new Porta_NAND(*this);}

  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Porta_OR: public Porta {
public:
  inline Porta_OR(): Porta() {}
  inline ~Porta_OR() {}
  ptr_Porta clone() const {return new Porta_OR(*this);}

  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Porta_NOR: public Porta {
public:
  inline Porta_NOR(): Porta() {}
  inline ~Porta_NOR() {}
  ptr_Porta clone() const {return new Porta_NOR(*this);}

  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Porta_XOR: public Porta {
public:
  inline Porta_XOR(): Porta() {}
  inline ~Porta_XOR() {}
  ptr_Porta clone() const {return new Porta_XOR(*this);}

  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Porta_NXOR: public Porta {
public:
  inline Porta_NXOR(): Porta() {}
  inline ~Porta_NXOR() {}
  ptr_Porta clone() const {return new Porta_NXOR(*this);}

  ostream &imprimir(ostream &O) const;

  bool_3S simular(const bool_3S in[]);
};

class Circuito {
private:
  unsigned Nin;      // Numero de entradas
  unsigned Nout;     // Numero de saidas
  unsigned Nportas;  // Numero de portas
  bool_3S *inputs;   // array com dimensao "Nin"
  int *id_out;       // array com dimensao "Nout"
  ptr_Porta *portas; // array com dimensao "Nportas"
  void limpar();
  void alocar(unsigned NI, unsigned NO, unsigned NP);  // ATENCAO: fora de construtor, sempre chamar antes limpar()
  void copiar(const Circuito &C);                      // ATENCAO: fora de construtor, sempre chamar antes limpar()
  bool verificar(void) const;
public:
  inline void setNIN(int novo){Nin = novo;}
  inline void setOUT(int novo){Nout = novo;}
  inline void setNUMPORTAS(int novo){Nportas = novo;}
  void calcularEntradas(unsigned I);      //calcular as entradas com o id I e salva em id_out
  inline Circuito():Nin(0),Nout(0),Nportas(0),inputs(NULL),id_out(NULL),portas(NULL) {}
  inline Circuito(const Circuito &C) {copiar(C);}
  void NovoCircuito(int numIN, int numOUT, int numPORTAS);
  inline ~Circuito() {limpar();}
  void setId_out(unsigned i, int N);
  inline void operator=(const Circuito &C) {if (this!=&C) {limpar(); copiar(C);}}
  inline unsigned getNumIn(){return Nin;}
  inline unsigned getNumOut(){return Nout;}
  inline unsigned getNumPortas(){return Nportas;}
  void digitar();
  void ler(const char *);
  ostream &imprimir(ostream &O=cout) const;
  void salvar(const char *) const;
  void digitarEntradas();
  void imprimirEntradas(void) const;
  void imprimirSaidas(bool_3S outputs[]);
  inline ptr_Porta getPortas(unsigned i) const {return portas[i];}
  inline int getId_out(unsigned i) const {return id_out[i];}
  inline bool_3S getInputs(unsigned i) const {return inputs[i];}
  void simular(int inp[], int tam);                             //grande loaco
  void setTipo_porta(int idporta, QString tipo);
  void setporta(int idporta, unsigned i, int N);
};

inline ostream &operator<<(ostream &O, const Circuito &C) {return C.imprimir(O);}

#endif // _CIRCUITO_H_
