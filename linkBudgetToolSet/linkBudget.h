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
#define      CLEARANCE_CONSTANT     8.657f          //  the constant used in calculation
#define      LINK_BUDGET_CONST      92.45f
#define      DEFAULT_MISC_LOSS      10.f            //  miscellaneous losses (dB)
#define      MIN_RELIABLE_MARGIN    10.f            //  when calculation max link range we assume 10dB is min required margin


// struct definitions
typedef struct {
    float fresDist_km;        //  half of the total distance
    float MaxRadius_m;       //  fresnel zone largest radius in meters
    float MinRad_m;          //  fresnel zone minimum allowable radius in meters
}Fresnel;


typedef struct LinkBudget{
    float Lm_dB;    // miscellaneous losses (fading margin, body loss, polarization mismatch, other losses...) (dB)
    float Lfs_dB;   // path loss, usually free space loss (dB)
    float RSSI;     //  received signal strenght indicator
    float linkMargin;   //  the result  (RSSI - Sensitivity) // for reliable link +10dB at least required

    struct Receiver{
        float Grx_dBi;  //  receiver antenna gain (dBi)
        float Lrx_dB;   //  receiver losses (coax, connectors...) (dB)
        float sensitivity;  //  receiver sensitivity
    }RX;

    struct Transmitter{
        float Ptx_dBm;  //  transmitter output power (dBm)
        float Gtx_dBi;  //  transmitter antenna gain (dBi)
        float Ltx_dB;   //  transmitter losses (coax, connectors...) (dB)
    }TX;

}Lbudget;


typedef struct Wave{
    float freq_ghz;    //  signal frequency in GHz
    float dist_km;     //  Distance between two antennas in kilometers
}Wave;


// struct variables
Fresnel fresnel;
Lbudget link;
Wave wave;         //  Properties of the wave


//Function signatures
extern void fresnelCalc(void);
extern void linkBudgetCalc(void);
extern void printFresnel(void);
extern void printLinkBudget(void);
extern void maxRange(void);     //  Calculates maximum theorical range of communication



#endif //LINKBUDGETTOOLSET_LINKBUDGET_H
