/*
 * ******************************************************************************
 *                                                              *
 * Created by Enes Mercan on 30.03.2021.                        *
 *                                                              *
 *      mail me : enesmercan1453@gmail.com                      ***************
 *      find me at : linkedin.com/in/enesmercan/                *
 *                                                              *
 *  All rights reserved ®                                       *
 *                                                              *
 *********************************************************************************
 *
*/




#ifndef LINKBUDGETTOOLSET_LINKBUDGET_H
#define LINKBUDGETTOOLSET_LINKBUDGET_H


// returns absolute value of the input
#define      ABS(X)                 ( (X >= 0) ? X : -X)

// constants to be used in calcutaions
#define      CLEARANCE_CONSTANT     8.657           //  the constant used in calculation
#define      LINK_BUDGET_CONST      92.45


// struct definitions
typedef struct {
    float fresDist_km;        //  half of the total distance
    float MaxRadius_m;       //  fresnel zone largest radius in meters
    float MinRad_m;          //  fresnel zone minimum allowable radius in meters
}Fresnel;


typedef struct {
    float Lm_dB;
    float Lfs_dB;
    float RSSI;
    float linkMargin;

    struct Receiver{
        float Grx_dBi;
        float Lrx_dB;
        float sensitivity;
    }RX;

    struct Transmitter{
        float Ptx_dBm;
        float Gtx_dBi;
        float Ltx_dB;
    }TX;

}Lbudget;


typedef struct Wave{
    float freq_ghz;    //  signal frequency in GHz
    float dist_km;     //  Distance between two antennas in kilometers
}Wave;


// extern struct variables
Fresnel fresnel;   //  Create an object here and assign the calculation constant
Lbudget link;      //
Wave wave;         //    Information about the wave


//Function signatures
extern void fresnelCalc(void);
extern void linkBudgetCalc(void);
extern void printFresnel(void);
extern void printLinkBudget(void);



#endif //LINKBUDGETTOOLSET_LINKBUDGET_H
