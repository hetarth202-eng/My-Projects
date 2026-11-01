#include<stdio.h>
#include<math.h>

//functions for calculating 4 band resistor
int band_04 ();
int CTN_04();//color to number
int NTC_04();//number to color 

//functions for calculating 5 band resistorR
int band_05();
int CTN_05();
int NTC_05();

int main(){

    int n , res ; 

    //welcome screen 
    printf("==========================================\n");
    printf("   Resistor color code decoder program    \n");
    printf("==========================================\n");
    printf("\n\n");

    // selecting the type of resistor 
    printf("Choose the resistor type \n");
    printf("1. 4 Band resistor \n");
    printf("2. 5 Band resistor \n");
    scanf("%d",&n);
    printf("\n");

    //using switch case 
    switch (n)
    {
    case 1 :
        band_04();
        break;
    case 2 :
        band_05();
        break;

    default:
        break;
    }
}

//the function for 4 band resistor
int band_04 (){
    /*the formula for calculating resistance :-
    res. = ((1st digit x 10) + 2nd digit ) x multiplier ± tolerance 
    */
   int x ;
   printf("Choose the operation for 4 band resistor\n");
   printf("1. Color code to number\n");
   printf("2. Number to color code\n");
   scanf("%d",&x);
   printf("\n");

   switch (x)
   {
    case 1:
        CTN_04();
        break;
    case 2 :
        NTC_04();
        break;
   default:
    break;
   }

}

//the funtion that find value by color code for 4 band resistor
int CTN_04(){
    int p , q , r  ;
    int res ;
    char* arr[]={"brown","red","green","blue","violet","grey","gold","silver","none\n"};
    int arr_num ;
    float t ;

    //getting the value 
    printf("\n\n 1. black \n 2. brown \n 3. red \n 4. orange \n 5. yellow \n 6.green \n 7. blue \n 8. violet \n 9. grey \n 10. white \n 11. gold \n 12. silver \n 13. none");
    
    //getting all the INFO.

    //1st band
    printf("\nEnter the 1st band :- ");
    scanf("%d",&p);
    for (int i = 1 ; i <= 10 ; i++){
        if(i==p){
            p = i - 1 ;
        }
    }

    //2nd band
    printf("\nEnter the 2nd band :- ");
    scanf("%d",&q);
    for (int i = 1 ; i <= 10 ; i++){
        if(i==q){
            q = i - 1 ;
        }
    }

    //3rd band
    printf("\nEnter the 3rd band (multiplier) :- ");
    scanf("%d",&r);
    for (int i = 1 ; i <= 10 ; i++ ){
        if (i == r ){
            r = i - 1  ; 
        }
    }
    if  (r == 11 ){
        r = (-1) ;
    }
    if (r == 12 ){
        r = (-2) ; 
    }

    // 4th band
    printf("\nFor the 4th band (tolerance) select :\n1.brown, 2.red, 3.green, 4.blue, 5.violet, 6.grey, 7.gold, 8.silver, 9.none : ");
    scanf("%d", &arr_num);

    switch (arr_num) {
        case 1: t = 1.0; 
            break; 
        case 2: t = 2.0;  
            break; 
        case 3: t = 0.5;  
            break; 
        case 4: t = 0.25; 
            break; 
        case 5: t = 0.1;  
            break; 
        case 6: t = 0.05; 
            break; 
        case 7: t = 5.0;  
            break; 
        case 8: t = 10.0; 
            break; // Silver
        case 9: t = 20.0; 
            break; // None
        default: 
            printf("Invalid tolerance selection!\n");
            t = 0.0; 
            break;
    }

    // calculating resistance
    res = ((p * 10) + q); 

    // displaying the resistance value
    printf("\nThe value of resistance is :- %d x 10^%d  +-  %.3f percentage\n", res, r, t);
}

// function that finds the color code by value for 4 band resistor
int NTC_04(){
    char* tol_col[] = {"brown","red","gold","silver","none"};
    char* arr[]= {"black", "brown" , "red" , "orange" , "yellow" , "green" , "blue" , "violet", "grey" , "white" , "gold" , "silver" , "none" };
    
    int tol_val  ;
    int tol;
    int x; 
    int y, z, mult;
    int count = 0; 

    //input of the resistance and tolerance
    printf("Enter the value of resistance (in ohm): ");
    scanf("%d", &x);
    printf("Enter the value of tolerance (1, 2, 5, 10, or 20) : ");
    scanf("%d",&tol_val);

    switch (tol_val){
    case 1: tol = 0 ;
        break;
    case 2: tol = 1  ;
        break;
    case 5: tol = 2;
        break;
    case 10: tol = 3 ;
        break;
    case 20: tol = 4 ;
        break;    
    default: break;
    }

    int temp = x; 

    // if the number is less than 10, it's invalid 
    if (temp < 10) {
        printf("Value too small for standard 4-band.\n");
        return 0; 
    }

    // keep dividing by 10 until only a 2-digit number is left
    while (temp >= 100) {
        temp = temp / 10;
        count++; 
    }  
    
    // now temp holds the first two digits 
    z = temp / 10; 
    y = temp % 10; 
    mult = count;  

    // printing the values
    printf("\n--- The color code for %d ohm ---\n", x);
    printf("Band 1 (1st digit) : %s\n", arr[z]); 
    printf("Band 2 (2nd digit) : %s\n", arr[y]); 
    printf("Band 3 (Multiplier): %s\n", arr[mult]); 
    printf("Band 4 (Tolerance) : %s\n", tol_col[tol]); 
    printf("---------------------------------\n");
    
    return 0;
}

//the function for 5 band resistor
int band_05 (){
    /*the formula for calculating resistance :-
    res. = ((1st digit x 100) + 2nd digit x 10 + 3rd digit ) x multiplier ± tolerance 
    */
   int x ;
   printf("Choose the operation for 5 band resistor\n");
   printf("1. Color code to number\n");
   printf("2. Number to color code\n");
   scanf("%d",&x);
   printf("\n");

   switch (x)
   {
    case 1: CTN_05();
        break;
    case 2 : NTC_05();
        break;
   default: break;
   }

}

//the funtion that find value by color code for 5 band resistor
int CTN_05(){
    int p , q , r , s ;
    int res ;
    float t ; 
    char* arr[]={"brown","red","green","blue","violet","grey","gold","silver","none"};
    int arr_num ;

    //getting the value 
    printf("\n\n 1. black \n 2. brown \n 3. red \n 4. orange \n 5. yellow \n 6.green \n 7. blue \n 8. violet \n 9. grey \n 10. white \n 11. gold \n 12. silver \n 13. none");
    
    //getting all the INFO.

    //1st band
    printf("\nEnter the 1st band :- ");
    scanf("%d",&p);
    for (int i = 1 ; i <= 10 ; i++){
        if(i==p){
            p = i - 1 ;
        }
    }

    //2nd band
    printf("\nEnter the 2nd band :- ");
    scanf("%d",&q);
    for (int i = 1 ; i <= 10 ; i++){
        if(i==q){
            q = i - 1 ;
        }
    }

    //3rd band 
    printf("\nEnter the 3rd band :- ");
    scanf("%d",&r);
    for (int i = 1 ; i <= 10 ; i++){
        if(i==r){
            r = i - 1 ;
        }
    }

    //4th band
    printf("\nEnter the 4th band (multiplier) :- ");
    scanf("%d",&s);
    for (int i = 1 ; i <= 10 ; i++ ){
        if (i == s ){
            s = i - 1  ; 
        }
    }
    if  (s == 11 ){
        s = (-1) ;
    }
    if (s == 12 ){
        s = (-2) ; 
    }

    // 5th band
    printf("\nFor the 5th band (tolerance) select :\n1.brown, 2.red, 3.green, 4.blue, 5.violet, 6.grey, 7.gold, 8.silver, 9.none : ");
    scanf("%d", &arr_num);

    switch (arr_num) {
        case 1: t = 1.0;  break; // Brown
        case 2: t = 2.0;  break; // Red
        case 3: t = 0.5;  break; // Green
        case 4: t = 0.25; break; // Blue
        case 5: t = 0.1;  break; // Violet
        case 6: t = 0.05; break; // Grey
        case 7: t = 5.0;  break; // Gold
        case 8: t = 10.0; break; // Silver
        case 9: t = 20.0; break; // None
        default: 
            printf("Invalid tolerance selection!\n");
            t = 0.0; 
            break;
    }

    // calculating resistance for 5-band 
    res = ((p * 100) + (q * 10) + r); 

    // displaying the resistance for 5 band resistor 
    printf("\nThe value of resistance is :- %d x 10^%d  +-  %g percentage\n", res, s, t);
}

// the function for converting number to color code for 5 band resistor 
int NTC_05(){
    char* tol_col[] = {"brown", "red", "green", "blue", "violet", "grey", "gold", "silver", "none"};
    char* arr[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white", "gold", "silver", "none"};
    
    float tol_val;
    int tol = 8; 
    int x; 
    int w, y, z, mult;
    int count = 0; 

    // input of the resistance and tolerance
    printf("Enter the value of resistance (in ohm, minimum 100): ");
    scanf("%d", &x);
    printf("Enter the value of tolerance (1, 2, 0.5, 0.25, 0.1, 0.05, 5, 10, or 20) : ");
    scanf("%f", &tol_val);

    // matching tolerance percentage to tol_col[] index
    if (tol_val == 1.0f)         tol = 0; // brown
    else if (tol_val == 2.0f)    tol = 1; // red
    else if (tol_val == 0.5f)    tol = 2; // green
    else if (tol_val == 0.25f)   tol = 3; // blue
    else if (tol_val == 0.1f)    tol = 4; // violet
    else if (tol_val == 0.05f)   tol = 5; // grey
    else if (tol_val == 5.0f)    tol = 6; // gold
    else if (tol_val == 10.0f)   tol = 7; // silver
    else if (tol_val == 20.0f)   tol = 8; // none
    else printf("Invalid tolerance entered, defaulting to 'none'.\n");

    int temp = x; 

    // keep dividing by 10 until only a 3-digit number is left
    while (temp >= 1000) {
        temp = temp / 10;
        count++; 
    }  
    
    // now temp holds the first three digits (e.g., 470)
    z = temp / 100;       
    y = (temp / 10) % 10; 
    w = temp % 10;        
    mult = count;  

    // printing the values
    printf("\n--- The color code for %d ohm ---\n", x);
    printf("Band 1 (1st digit) : %s\n", arr[z]); 
    printf("Band 2 (2nd digit) : %s\n", arr[y]); 
    printf("Band 3 (3rd digit) : %s\n", arr[w]); 
    printf("Band 4 (Multiplier): %s\n", arr[mult]); 
    printf("Band 5 (Tolerance) : %s\n", tol_col[tol]); 
    printf("---------------------------------\n");
    
    return 0;
}