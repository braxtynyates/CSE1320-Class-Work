#include <stdio.h>

//turns on the given feature
void enableFeature(unsigned *config, unsigned int mask){
    *config |= mask;
}
//turns off the given feature 
void disableFeature(unsigned *config, unsigned int mask){
    *config &= ~mask;
}
//toggles the feature to the oppisite of its current state
void toggleFeature(unsigned *config, unsigned int mask){
    *config ^= mask;
}
//checks to see if a feature is on or off and returns 1 or 0 correnspondingly 
int isFeatureEnabled(unsigned int config, unsigned int mask){
    if (config & mask){
        return 1;
    }else{
        return 0;
    }
}
//transforms the value into its binary form 
void displayBinary(unsigned int config){
    for (int i = 7; i >= 0; i--){
        printf("%d", ( config >> i) & 1);
        }
        printf("\n");
    }
//shows all features and wether they are on or off
void displayConfiguration(unsigned int config){
    if (isFeatureEnabled(config, 1 << 0)){
        printf ("GUEST_ACCESS is ON\n");
    }else{
        printf ("GUEST_ACCESS is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 1)){
        printf ("REMOTE_ACCESS is ON\n");
    }else{
        printf ("REMOTE_ACCESS is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 2)){
        printf ("LOGGING is ON\n");
    }else{
        printf ("LOGGING is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 3)){
        printf ("ENCRYPTION is ON\n");
    }else{
        printf ("ENCRYPTION is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 4)){
        printf ("FIREWALL is ON\n");
    }else{
        printf ("FIREWALL is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 5)){
        printf ("TWO_FACTOR is ON\n");
    }else{
        printf ("TWO_FACTOR is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 6)){
        printf ("AUTO_UPDATE is ON\n");
    }else{
        printf ("AUTO_UPDATE is OFF\n");
    }
    if (isFeatureEnabled(config, 1 << 7)){
        printf ("ADMIN_MODE is ON\n");
    }else{
        printf ("ADMIN_MODE is OFF\n");
    }
    


}
//checks to see if the current config has ADMIN_MODE, FIREWALL, and ENCRYPTION on
int isSecure(unsigned int config){
    if ( isFeatureEnabled(config, 1<<3)){
        if (isFeatureEnabled(config, 1 << 4)){
            if (isFeatureEnabled(config, 1 << 7)){
                return 1;
            }else {
                return 0;
            }
        }else {
                return 0;
            }
    }else {
                return 0;
            }
}

int main() {

    //mask for each security feature
    unsigned int GUEST_ACCESS = 1 << 0;
    unsigned int REMOTE_ACCESS = 1 << 1;
    unsigned int LOGGING = 1 << 2;
    unsigned int ENCRYPTION = 1 << 3;
    unsigned int FIREWALL = 1 << 4;
    unsigned int TWO_FACTOR = 1 << 5;
    unsigned int AUTO_UPDATE = 1 << 6;
    unsigned int ADMIN_MODE = 1 << 7;
    
    //config for what features are on
    unsigned int securityConfig = 0;

    //enables the features FIREWALL, LOGGING, and ENCRYPTION
    enableFeature(&securityConfig, FIREWALL); 
    enableFeature(&securityConfig, LOGGING);
    toggleFeature(&securityConfig, ENCRYPTION);

    //prints out the current binary conffig of 00011100
    displayBinary(securityConfig);

    //disables the feature LOGGING 
    disableFeature(&securityConfig, LOGGING);

    //prints out the current binary config of 00011000
    displayBinary(securityConfig);

    //toggles FIREWALLS wether its on or off in this case its on so it turns off 
    toggleFeature(&securityConfig,FIREWALL);

    //prints out the current binary config of 00001000
    displayBinary(securityConfig);
    
    // sends info to function functino returns value of either 1 or 0 to tell the if statment wether the feature is on or off
    // in this case its on
    if (isFeatureEnabled(securityConfig, ENCRYPTION)){
        printf("Feature is on \n");
    }else{
        printf("Feature is off \n");
    }

    //same this as above but this time its off
     if (isFeatureEnabled(securityConfig, REMOTE_ACCESS)){
        printf("Feature is on \n");
    }else{
        printf("Feature is off \n");
    }

    //shows off all configuration and wether they are on or off
    displayConfiguration(securityConfig);

    //checks the current values to see if the systme is secure currently is not 
    if (isSecure(securityConfig)){
        printf("system satisfies the security policy\n");
    }else{
        printf("system does not satisfy the security policy\n");
    }
    

    //Architect's Challenge
    unsigned int x = 1;
    x = x << 1; // repersents x2
    printf("%d\n",x);
    x = x << 2; // repersents x4
    printf("%d\n",x);
    x = x << 3; // repersents x8
    printf("%d\n",x);
    x = x >> 1; // repersents /2
    printf("%d\n",x);
    // this can not work when working with negative numbers and shifting right as it might turn it positive
    return 0;
} 
 
/*TWO COMPLEMENTS CHALLENGE: 11111011
    1. Is this value positive or negative if interpreted as an 8-bit two's complement number? negative the first digit is a 1 
instead of a 0, 0 would indicate that its positive.

    2. What decimal value does it represent?
    [-]
    00000100
    +1
    00000101
         4+1=5
    -5
*/