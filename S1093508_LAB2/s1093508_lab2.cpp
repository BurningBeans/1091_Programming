#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double weight, height, BMI;
    cout << "Input weight (kg): ";
    cin >> weight;
    cout << "Input height (m): ";
    cin >> height;
    //input check
    if(weight < 20 || weight > 200)
    {
        cout << "Invalid weight (>= 20kg and <= 200kg)";
        return 0;
    }
    else if(height < 0.9 || height > 2.5)
    {
        cout << "Invalid height (>= 0.9m and <= 2.5m)";
        return 0;
    }

    BMI = weight/pow(height,2);
    
    cout << "# Your weight(kg): " << weight << endl;
    cout << "# Your height(m): " << height << endl;
    cout << "# Your BMI: " << BMI << endl;

    //BMI statement
    if(BMI > 70)
    {
        cout <<"# Your BMI level is Unreasonably large \n";
    }
    else if(BMI >= 60)
    {
        cout << "# Your BMI level is Highly severely obese \n";
    }
    else if (BMI >= 50)
    {
        cout << "# Your BMI level is Severely obese \n";
    }
    else if (BMI >= 40)
    {
        cout << "# Your BMI level is Obese \n";
    }
    else if (BMI >= 25)
    {
        cout << "# Your BMI level is Overweight \n";
    }
    else if (BMI >= 18.5)
    {
        cout << "# Your BMI level is Normal \n";
    }
    else if (BMI >= 16)
    {
        cout << "# Your BMI level is Underweight \n";
    }
    else if (BMI >= 15)
    {
        cout << "# Your BMI level is Severely underweight \n";
    }
    else if (BMI >= 10)
    {
        cout << "# Your BMI level is Highly severely underweight \n";
    }
    else
    {
        cout << "# Your BMI level is Unreasonably underweight \n";
    }

    //advices 30%
    
    if (BMI > 25)
    {
        double targetweight;
        targetweight = pow(height, 2) * 25;//25 = weight * height^2
        cout << "# Decrease your weight to " << targetweight << " kg to bring your BMI value to 25 \n";
    }
    else if(BMI < 18.5)
    {
        double targetweight;
        targetweight = pow(height, 2) * 18.5;
        cout << "# Increase your weight to " << targetweight << " kg to bring your BMI value to 18.5 \n";
    }
    system("pause");
    return 0;
}
