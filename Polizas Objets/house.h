//
// Created by Alexis Ortiz ceceña on 22/01/24.
//

#ifndef ESTRUCTURAS_DE_DATOS_HOUSE_H
#define ESTRUCTURAS_DE_DATOS_HOUSE_H


class house {
    private:
        string house_Antiquity;
        bool electronic_Devices;
    public:
        string get_House_Antiquity(){
            return house_Antiquity;
        };
        void set_House_Antiquity(){
            string user_Answer;
             std::cout<<"Ingrese la anguiedad de la casa: ";
            std::cin>>user_Answer;
        };
        bool get_Electronic_Devices(){
            return  electronic_Devices;
        };
        void set_Electronic_Devices(){
            int user_Answer_Flag = 0;
            cout<<"Ingrese la respuesta en numeros\n 1.Si\n 2.No"<<enl;
            cout<<"Usted tiene dispositivos electronicos: ";
            cin>>user_Answer_Flag;
            if(user_Answer_Flag == 1 ){
                electronic_Devices = true;
            } else{
                electronic_Devices = false;
            };
        };
};

class date{
    private:
        int hora;
        int segundo;
        int minuto;
    public:
        void cambiarhora();
        void cambiarSegundo();
        void cambiarMinuto();
    date(int inicioConSegundo){
        segundo = inicioConSegundo;
    };
};

#endif //ESTRUCTURAS_DE_DATOS_HOUSE_H
