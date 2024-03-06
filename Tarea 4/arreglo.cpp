#include <bits/stdc++.h>
#define capacidad 40

using namespace std;
#define ss second
#define ff first
#define pb push_back
#define all(s) s.begin(), s.end()
#define enl "\n"
#define fast                 \
    ios::sync_with_stdio(0); \
    cout.tie(0);             \
    cin.tie(0);
#define sz(s) int(s.size())
#define fore(i, n) for (int i = 0; i != n; ++i)

using namespace std;
typedef long long lli;
typedef pair<lli, lli> ii;
typedef vector<char> vhar;
typedef vector<lli> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vi> vvi;




template <typename objeto>
class arreglo_lista{
public:
    explicit arreglo_lista (int tam):i{tam},cap{i+capacidad	}{
        arr=new objeto[cap];
    }
    arreglo_lista (const arreglo_lista &rhs):i{rhs.i},cap{rhs.cap}, arr{nullptr}{
        arr=new objeto[cap];
        for(int k=0;k<i;k++)
            arr[k]=rhs.arr[k];
    }
    arreglo_lista(arreglo_lista &&rhs){
        rhs.i=0;
        rhs.cap=0;
        rhs.arr=nullptr;
    }
    arreglo_lista(){
        i=0;
        cap=capacidad;
        arr=new objeto[capacidad];
    }
    ~arreglo_lista(){
        delete []arr;
    }
    arreglo_lista & operator = (const arreglo_lista &rhs){
        arreglo_lista copia = rhs;
        swap(cap, copia.cap);
        swap(i, copia.i);
        swap(arr, copia.arr);
        return *this;
    }
    arreglo_lista & operator = (arreglo_lista &&rhs){
        swap(i, rhs.i);
        swap(cap, rhs.i);
        swap(arr, rhs.arr);
        return *this;
    }
    void push_final(const objeto &rhs){
        if (i == cap)
            reservar(cap + 1); // invocar metodo para aumentar el espacio
        arr[i] = rhs;
        i++;
    }
    void push_final(objeto &&rhs){
        if (i == cap)
            reservar(cap + 1); // invocar metodo para aumentar el espacio
        arr[i] = std::move(rhs);
        i++;
    }
    void pop_final (){
        if(!vacia())//metodo
            i--;
    }
    objeto & operator [] (int indice){
        return arr[indice];
    }
    const objeto & operator [](int indice)const{
        return arr[indice];
    }
    void nueva_capacidad(int nueva_cap){
        if(nueva_cap > cap ){
            reservar(nueva_cap);
            cap = nueva_cap;
        }
    }
    int size(){
        return i;
    }
    void reservar(int nueva_capacidad){
        objeto* nuevo_arr = new objeto[nueva_capacidad];
        for (int k = 0; k < i; k++) {
            nuevo_arr[k] = std::move(arr[k]);
        }
        delete[] arr;
        arr = nuevo_arr;
    }
    int vacia(){
        if(i==0)
            return 1;
        else
            return 0;
    }
    void pop(int indice) {
        if (indice < 0 || indice >= i) {
            cout << "Índice fuera de rango." << endl;
            return;
        }
        for (int j = indice; j < i - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        i--;
    }
private:
    int i;
    int cap;
    objeto *arr;
};



class student{
    private:
        string fullName;
        long long int student_code;
        string carrer;
        bool status;
        arreglo_lista<arreglo_lista<string>> classes;
    public:
        student(){
            status = true; // constructor
        }
        void setFullName(string name){
            fullName = name;
        }
        string getFullName(){
            return fullName;
        }
        void setStudent_code(long long int code){
            student_code = code;
        }
        long long int getStudentCode(){
            return student_code;
        }
        void setCarrer(string student_path){
            carrer = student_path;
        }
        string getCarrer(){
            return carrer;
        }
        void setClasees(int num_classes){
            fore(i,num_classes){  // obtenemos los valores para meterlos al arr_clases
                string response;
                cout<<"Ingrese la clave de la materia "<<i<<": ";cin>>response;
                classes[i].push_final(response);
                cout<<"Ingrese la seccion de la materia "<<i<<": ";cin>>response;
                classes[i].push_final(response);
                cout<<"Ingrese el NRC de la materia " <<i<< ": ";cin>>response;
                classes[i].push_final(response);
                cout<<"Ingrese el horario de la materia " <<i<< ": ";cin>>response;
                classes[i].push_final(response);
                cout<<"Ingrese el profesor de la materia" <<i<< " : ";cin>>response;
                classes[i].push_final(response);
                cout<<"Ingrese el nombre de la materia" <<i<< " : ";cin>>response;
                classes[i].push_final(response);
            }
        }
        arreglo_lista<arreglo_lista<string>> GetClasses(){
            return classes;
        }

};

student create_student(){
    string name;
    long long int code;
    string carrer;
    int num_classes;
    arreglo_lista<arreglo_lista<string>> arr_clases; //Primero obtenemos los valores
    cout<<"REGISTRACION"<<enl;
    cout<<"Ingrese el nombre: ";cin>>name;
    cout<<"Igrese el codigo de estudiente: ";cin>>code;
    cout<<"Ingrese la carrera: ";cin>>carrer;
    cout<<"Ingrese el numero de clases: ";cin>>num_classes;

    cout<<"---------------"<<enl;
    student creator; //creamos el objeto
    creator.setFullName(name);
    creator.setStudent_code(code);
    creator.setCarrer(carrer);
    //cout<<"aqui-peta"<<enl;
    creator.setClasees(num_classes);
    //arreglo_lista<arreglo_lista<string>> s = creator.GetClasses();
   // cout<<enl<<"acaentro: " <<s[0][1]<<enl;
    return creator;
}
void test(student aca){

}

student lookup_student(arreglo_lista<student> estudiantes){ // busca el estudiante en el arreglo de estudiantes.
    string s;                                               // tambien pude a ver devuelto el indeice de donde estaba el estudiante :)). asi podria eliminarlos tambien
    student finded;                                         // pero devuelvo un objeto tipo student.
    bool flag = false;
    cout<<"BUSQUEDA"<<enl;

    cout<<"Ingresa el nombre (exacto) a buscar: ";cin>>s;
    fore(i,estudiantes.size()){
        if(estudiantes[i].getFullName() == s){
            finded = estudiantes[i];
            flag = true;
            break;
        }
    }
    cout<<"---------------"<<enl;
    test(finded);
    return finded;

}

void show_student(student Student){   // Imprime toda la info del estudiante
    cout<<"Nombre del alumno: "<< Student.getFullName()<<enl;
    cout<<"Codigo del alumno: "<< Student.getStudentCode()<<enl;
    cout<<"Carrera del alumno: "<< Student.getCarrer()<<enl;
    arreglo_lista< arreglo_lista<string>> classes = Student.GetClasses();
    // cout<<classes.size()<<enl<<enl; SIZE SIEMPRE ES 0?
    fore(i,classes.size()){
        cout<<"Clave #"<<i<<" :" <<classes[i][0];
        cout<<"Seccion #"<<i<<" :" <<classes[i][1];
        cout<<"NRC #"<<i<<" :" <<classes[i][2];
        cout<<"Horario #"<<i<<" :" <<classes[i][3];
        cout<<"Profesor #"<<i<<" :" <<classes[i][4];
        cout<<"Nombre de la materia #"<<i<<" :" <<classes[i][5];
    }
    cout<<"-------------------"<<enl;
}


void menu(){ // funcion menu
    int ans = 0;
    arreglo_lista<student> estudiantes;
    while(ans < 3 and ans >= 0){
        cout<<"1.Registrar nuevo estudiante.\n2.Buscar estudiante\n3.Salir\n>> ";
        cin>>ans;
        if(ans == 1){
            student created = create_student();
            //cout<<"salio"<<enl;
            estudiantes.push_final(created);
        }
        else if(ans == 2){
            student finded = lookup_student(estudiantes);
            show_student(finded);
        }
        else if( ans == 3 ){
            test();
        }
    }
}

int main(){
    menu(); // llama a la funcion menu
	return 0;
}
