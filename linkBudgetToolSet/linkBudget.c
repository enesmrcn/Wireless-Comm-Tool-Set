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
    link.TX.Ltx_dB = ABS(link.TX.Ltx_dB);
    link.RX.Lrx_dB = ABS(link.RX.Lrx_dB);

    link.Lfs_dB = 20 * log10f(wave.freq_ghz);
    link.Lfs_dB += 20 * log10f(wave.dist_km);
    link.Lfs_dB += (float) LINK_BUDGET_CONST;


    link.RSSI = (link.TX.Ptx_dBm) + (link.TX.Gtx_dBi) - (link.TX.Ltx_dB);
    link.RSSI +=  ( (link.RX.Grx_dBi) - (link.RX.Lrx_dB) - (link.Lfs_dB) );
    link.linkMargin = link.RSSI - link.RX.sensitivity;

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