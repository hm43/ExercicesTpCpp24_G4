#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Employee{
private:
    string id;
    string nom;
    double salaire;
    static int employeeCount;
    static double bonusPourcentage;
public:
    Employee(){
        employeeCount++;
        id = "EMP_"+to_string(employeeCount);
        nom = "";
        salaire = 0;
    }
    Employee(string n, double s){
        employeeCount++;
        id = "EMP_"+to_string(employeeCount);
        nom = n;
        salaire = s;
    }
    Employee(const Employee &e){
        employeeCount++;
        id = "EMP_"+to_string(employeeCount);
        nom = e.nom;
        salaire = e.salaire;
    }
    ~Employee(){
        employeeCount--;
    }
    // e1 + e2
    double operator+(Employee &e){
        return salaire + e.salaire;
    }
    // 1000.0 + e2
    friend double operator+(double valeur, Employee &e){
        return valeur + e.salaire;
    }
    // cout<<e1;
    friend ostream& operator<<(ostream& out, const Employee &e){
        out<<endl<<e.id<<endl<<e.nom<<endl<<e.salaire<<endl;
        return out;
    }
    void promoter(double montant){
        salaire += montant;
    }
    static double averageSalary(vector<Employee> emps){
        double s = 0;
        for(Employee &e: emps){
            s+= e.salaire;
        }
        return s/emps.size();
    }
    static void setBonusPercentage(double bonus){
        bonusPourcentage = bonus;
    }
    void awardBonus(){
        salaire += salaire * (bonusPourcentage / 100);
    }
};
int Employee::employeeCount = 0;
double Employee::bonusPourcentage = 0;
int main(){
    vector<Employee> employees;
        Employee::setBonusPercentage(10.0); // 10% bonus
        Employee emp1("Alice", 50000.0);
        Employee emp2("Bob", 60000.0);
        Employee emp3("Charlie", 70000.0);
        employees.push_back(emp1);
        employees.push_back(emp2);
        employees.push_back(emp3);
    cout << "Somme des employees 1 et 2: " << emp1 + emp2 << endl;
    cout << "Somme de 1000.0 et le salaire de emp2: " << 1000 + emp2 << endl;
        emp3.promoter(5000.0);
        cout << "Employee apres promotion: " << emp3 << endl;
        cout << "Salaire moyenne: " << Employee::averageSalary(employees) << endl;
        for (auto& emp : employees) {
            emp.awardBonus();
        }
        cout << "Employees apres bonus:"<<endl;
        for (const auto& emp : employees) {
            cout << emp << endl;
        }

    return 0;
}
