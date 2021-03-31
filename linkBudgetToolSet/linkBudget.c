/*
 * ***************************************************************************************************
 *
 * Created by Enes Mercan on 30.03.2021.
 *
 *      mail me : enesmercan1453@gmail.com
 *      find me at : linkedin.com/in/enesmercan/
 *
 *  All rights reserved ®
 *
 ***************************************************************************************************
*/



#include "linkBudget.h"
#include <math.h>
#include <stdio.h>


extern void fresnelCalc(void) //  takes distance in km and freq in GHz to perform calculations
{
    fresnel.MaxRadius_m = CLEARANCE_CONSTANT * (float) sqrt((double) wave.dist_km / wave.freq_ghz);
    fresnel.fresDist_km = wave.dist_km / 2;
    fresnel.MinRad_m = (float) fresnel.MaxRadius_m * 0.6f;
}

extern void linkBudgetCalc(void)
{
    link.TX.Ltx_dB      = ABS(link.TX.Ltx_dB);          //  Takes the absolute to avoid any conflict
    link.RX.Lrx_dB      = ABS(link.RX.Lrx_dB);           //  Takes the absolute to avoid any conflict
    link.Lm_dB          = ABS(link.Lm_dB);               //  Takes the absolute to avoid any conflict
    link.RX.sensitivity = ABS(link.RX.sensitivity);       //  Takes the absolute to avoid any conflict

    if (link.Lm_dB == 0)    //  Misc Losses by default is 10dBm
        link.Lm_dB =  DEFAULT_MISC_LOSS;

    link.Lfs_dB = 20 * log10f(wave.freq_ghz);
    link.Lfs_dB += 20 * log10f(wave.dist_km);
    link.Lfs_dB += LINK_BUDGET_CONST;


    link.RSSI = (link.TX.Ptx_dBm) + (link.TX.Gtx_dBi) - (link.TX.Ltx_dB);
    link.RSSI +=  ( (link.RX.Grx_dBi) - (link.RX.Lrx_dB) - (link.Lfs_dB) - (link.Lm_dB));
    link.linkMargin = link.RSSI + link.RX.sensitivity;

}

extern void printFresnel(void)
{
    putchar(10);
    puts("******** FRESNEL **** RESULTS **********");
    printf("\n%-36s%.2lf km", "Total Distance", wave.dist_km);
    printf("\n%-36s%.2lf GHz", "Frequency", wave.freq_ghz);
    printf("\n%-36s%.2lf km", "Fresnel Zone Distance", fresnel.fresDist_km);
    printf("\n%-36s%.2lf m", "Recommended Propagation Altitude", fresnel.MaxRadius_m);
    printf("\n%-36s%.2lf m", "Minimum Propagation Altitude", fresnel.MinRad_m);
    putchar(10);
    puts("****************************************");

}

extern void printLinkBudget(void)
{
    putchar(10);
    puts("******** Link Budget Results **************");
    printf("\n%-25s%.2lf dBm", "TX Output Power", link.TX.Ptx_dBm);
    printf("\n%-25s%.2lf dBi", "TX Antenna Gain", link.TX.Gtx_dBi);
    printf("\n%-25s%.2lf dB",  "TX Cable Loss", link.TX.Ltx_dB);
    printf("\n%-25s%.2lf dB",  "Space Loss", link.Lfs_dB);
    printf("\n%-25s%.2lf dBi", "RX Antenna Gain", link.RX.Grx_dBi);
    printf("\n%-25s%.2lf dB",  "RX Cable Loss", link.RX.Lrx_dB);
    printf("\n%-25s%.2lf dBm", "RX Sensitivity", link.RX.sensitivity);
    printf("\n%-25s%.2lf dBm", "RSSI", link.RSSI);
    printf("\n%-25s%.2lf dB",  "Link Margin", link.linkMargin);


    putchar(10);
    puts("*****************************************");

}

extern void maxRange(void)
{

    float range, tempVal;

    if (link.Lm_dB == 0.f)    //  Misc Losses by default is 10dBm
        link.Lm_dB =  DEFAULT_MISC_LOSS;
    else
        link.RX.sensitivity = ABS(link.RX.sensitivity);   //  Takes the absolute to avoid any conflict


    tempVal = (link.TX.Ptx_dBm) + (link.TX.Gtx_dBi) - (link.RX.Lrx_dB) - (link.TX.Ltx_dB)
                - (link.Lm_dB) + (link.RX.Grx_dBi) + (link.RX.sensitivity)
                    - 92.45f - (20 * log10f(wave.freq_ghz));

    range = tempVal;
    range /= 20;
    range = powf(10.f, range);

    tempVal -= MIN_RELIABLE_MARGIN;
    tempVal /= 20;
    tempVal = powf(10.f, tempVal);

    // print the results
    putchar(10);
    puts("****************************************");
    printf("theoretical max range --> %.3f km", range);
    putchar(10);
    printf("practical max range --> %.3f km", tempVal);     // Taken into account probability of 10dB loss margin in air (recommended)
    putchar(10);                                            //  recommended by RF designers
    puts("****************************************");
}