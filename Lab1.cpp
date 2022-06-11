#include <iostream>
using namespace std;

struct patient
{
    int symptoms;
    bool pcrtest;
    bool result;
    patient(int sympts)
    {
        symptoms = sympts;
        pcrtest = false;
        result = false;
    }
};

void PCRtest(patient *a)
{
    int choice;
    cout << "Did you take PCR test?" << endl;
    cout << "1-Yes\n2-No" << endl;
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        int result;
        (*a).pcrtest = true;
        cout << "Positive or negative?" << endl;
        cout << "1-Positive \n2-Negative" << endl;
        cin >> result;
        if (result == 1)
        {
            (*a).result = true;
        }
        if (result == 2)
        {
            (*a).result = false;
        }
        cout << endl;
    }
    if (choice == 2)
    {
        (*a).pcrtest = false;
        cout << endl;
    }
}

void Symptoms(patient *a)
{
    int n = 0;
    int choice;
    cout << "Which of the following symptoms do you have?" << endl;
    cout << "0-No \n1-Fever \n2-Cough \n3-Difficulty breathing \n4-Fatigue \n5-Muscle or body aches \n6-Headache \n7-Lost of taste or smell \n8-Sore throat \n9-Runny nose \n10-Nausea or vomiting \n11-Diarrhea" << endl;
    cin >> choice;
    while (choice != 0)
    {
        n = n + 1;
        cout << "Do you have other symptoms?" << endl;
        cout << "0-No \n1-Fever \n2-Cough \n3-Difficulty breathing \n4-Fatigue \n5-Muscle or body aches \n6-Headache \n7-Lost of taste or smell \n8-Sore throat \n9-Runny nose \n10-Nausea or vomiting \n11-Diarrhea" << endl;
        cin >> choice;
    }
    cout << n << " symptoms" << endl;
    cout << endl;
    (*a).symptoms = n;
}

int main()
{
    struct patient covid = patient(0);
    cout << "Covid-19 Diagnosis" << endl;
    cout << endl;

    Symptoms(&covid);
    PCRtest(&covid);
    if (covid.pcrtest == true)
    {
        if (covid.result == true)
        {
            cout << "You have covid" << endl;
        }
        if (covid.result == false)
        {
            if (covid.symptoms == 0)
            {
                cout << "You don't have covid" << endl;
            }
            if (covid.symptoms != 0)
            {
                cout << "You have other disease, not covid" << endl;
            }
        }
    }
    if (covid.pcrtest == false)
    {
        if ((covid.symptoms) > 3)
        {
            cout << "You may have covid" << endl;
        }
        if ((covid.symptoms) < 4)
        {
            cout << "You have other disease, not covid" << endl;
        }
    }
}
