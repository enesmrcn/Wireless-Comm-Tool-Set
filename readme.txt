
--> You can calculate the distance of wireless communication between receiver and transmitter
--> Can easily estimate the minimum and recommended altitude of the antennas to avoid reflections and blockages


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


//  ***************************************************************************************************

/*          Propagation Altitude Calculation            */

/*
 *  enter the distance between antennas in km  -->
 *      wave.dist_km = 6;
 *
 *  enter the frequency of your wave in GHz
 *      wave.freq_ghz = 2.4
 *
 *  call the function " void fresnelCalc(void) " to perform scientific calculations
 *
 *  call " printFresnel(void) " to see the performed results
 *
 * */

//  ***************************************************************************************************

/*          Link Margin Calculation          */

/*
 *  enter the distance between antennas in km  -->
 *      wave.dist_km = 6;
 *
 *  enter the frequency of your wave in GHz
 *      wave.freq_ghz = 2.4
 *
 *  enter the TX Power Output of your transmitter in dBm
 *      link.TX.Ptx_dBm = 20;
 *
 *  enter the TX Antenna Gain in dBi
 *      link.TX.Gtx_dBi = 14;
 *
 *  enter the TX Cable Loss in dB
 *      link.TX.Ltx_dB = 2;
 *
 *  enter the RX Antenna Gain in dBi
 *      link.RX.Grx_dBi = 2.2;
 *
 *  enter the RX Cable Loss in dB
 *      link.RX.Lrx_dB = 2;
 *
 *  enter the RX Sensitivity in dBm
 *      link.RX.sensitivity = -147.2;
 *
 *  call the function " linkBudgetCalc(); " to perform scientific calculations
 *
 *  call " printLinkBudget(); " to see the performed results
 *
 * */

//  ***************************************************************************************************

/****************************	Example Codes ******************************************************/

// Fresnel Tunnel Diameter calculation
    wave.dist_km = 1.f;
    wave.freq_ghz = 2.4f;

    fresnelCalc();    //  perform the calculation (necessarily)
    printFresnel(); //  printf results

//_________________________________________________________________________________________

// link budget  calculation

    link.TX.Ptx_dBm = 30.f;
    link.TX.Gtx_dBi = 2.f;
    link.TX.Ltx_dB = 2.f;
    link.RX.Grx_dBi = 2.f;
    link.RX.Lrx_dB = 2.f;
    link.RX.sensitivity = -147.2f;

    linkBudgetCalc();    //  perform the calculation (necessarily)
    printLinkBudget();   //  to print results


//_________________________________________________________________________________________

// maximum range calculation
    wave.freq_ghz = 0.868f;
    link.TX.Ptx_dBm = 30.f;
    link.TX.Gtx_dBi = 2.f;
    link.TX.Ltx_dB = 2.f;
    link.RX.Grx_dBi = 2.2f;
    link.RX.Lrx_dB = 2.f;
    link.RX.sensitivity = -147.2f;

    maxRange();    //  perform the calculation (necessarily)

//_________________________________________________________________________________________


//  ***************************************************************************************************

/****************************	  THE END      ******************************************************/

