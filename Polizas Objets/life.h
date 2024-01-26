//
// Created by Alexis Ortiz ceceña on 22/01/24.
//

#ifndef ESTRUCTURAS_DE_DATOS_LIFE_H
#define ESTRUCTURAS_DE_DATOS_LIFE_H


class Life{
    private:
        string birth;
        vector<string> benefits;
    public:
        string get_Birth(){
            return birth;
        };
        void set_Birth(){
            cout<<"Ingrese la fecha de nacimiento del asegurado (MM/DD/YY): ";
            cin>>birth;
        };
        vector<string> get_benefits(){
            return benefits;
        };
        void set_benefits(){
            int benefits_size;
            cout<<"Ingrese la cantidad de covertira que desea en el plan de vida: ";
            cin>>benefits_size;cout<<enl;
            for(int it = 0 ; it != benefits_size ; it++){
                string temporary_answer;
                cout<<"Ingrese la covertura numero "<< it + 1 <<": ";
                cin>>temporary_answer;
                benefits.push_back(temporary_answer);
            }
        };

};

#endif //ESTRUCTURAS_DE_DATOS_LIFE_H