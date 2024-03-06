//
// Created by Alexis Ortiz ceceña on 22/01/24.
//

#ifndef ESTRUCTURAS_DE_DATOS_USER_H
#define ESTRUCTURAS_DE_DATOS_USER_H

class user {
    private:
        int id;
        string Client_Name;
        string age;
        string address;
        int amount;
        int monthly_Payment;



    public:
        Life vida;
        automovile car;
        house House;
        string get_Client_Name(){
            return Client_Name;
        };
        string get_age(){
            return age;
        };
        string get_Address(){
            return address;
        };
        int get_id(){
            return id;
        };
        void set_id(int x){
            id = x;
        }
        int get_amount(){
            return amount;
        }
        int get_monthly_Payments(){
            return monthly_Payment;
        };
        void set_Client_Name(){
            cout<<"Ingrese el nombre del cliente responsable de la poliza: ";
            cin>>Client_Name;
        };
        void set_addres(){
            cout<<"Ingresa el domicilio actual: ";
            cin>>address;
        };
        void set_age(){
            cout<<"Ingrese la edad de cliente responsable de la poliza: ";
            cin>>age;
        };
        void set_amount(){
            cout<<"Ingrese la cantidad a asegurar: ";
            cin>>amount;
        };
        void set_Monthly_Payment(){
            cout<<"Ingrese la prima mensual: ";
            cin>>monthly_Payment;
        };
        user (Life new_user){
            vida = new_user;
            vida.set_Birth();
            vida.set_benefits();
        };
        user(automovile new_user){
            car = new_user;
            car.setMake();
            car.setModel();
            car.setYear();
            car.setLinces_Plate();
            car.setState();
        };
        user(house new_user){
            House = new_user;
            House.set_Electronic_Devices();
            House.set_House_Antiquity();
        };
};



#endif //ESTRUCTURAS_DE_DATOS_USER_H
