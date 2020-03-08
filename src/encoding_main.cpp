#include <iostream>
#include <vector>



using namespace std;

//#define DEBUG_PRINT

/*
 *structure that handels the  levels ranges for each level
 * 
 */
typedef struct Hys_range 
{
    public:

    Hys_range(uint8_t _level, uint8_t _upper, uint8_t _lower):level(_level),
                upper(_upper), lower(_lower){}


    // level form 0 to 4
    uint8_t level;
    
    //presentage form 0 to 100 
    uint8_t upper;
    uint8_t lower;
}Hys_range;

// initialzing the function
uint8_t hysteresis_level_evaluator(uint8_t current_prcent, vector  < Hys_range*> & threshold );



int main()
{   
    
    // Initilazing the levels
    vector  < Hys_range*>  threshold;

    threshold.push_back(new Hys_range(1, 15, 10));
    threshold.push_back(new Hys_range(2, 40, 35));
    threshold.push_back(new Hys_range(3, 65, 60));
    threshold.push_back(new Hys_range(4, 90, 95));




    // executing the actual level


    uint8_t level = hysteresis_level_evaluator(5, threshold);
    cout << "Last Input: " << 0 << "  Current Input: "<<  5 <<"  Level: "<< static_cast<int>(level) << endl;

    level = hysteresis_level_evaluator(45, threshold);
    cout << "Last Input: " << 5 << "  Current Input: "<<  45 <<" Level: "<< static_cast<int>(level) << endl;

    level = hysteresis_level_evaluator(36, threshold);
    cout << "Last Input: " << 45 << " Current Input: "<<  36 <<" Level: "<< static_cast<int>(level) << endl;

    level = hysteresis_level_evaluator(0, threshold);
    cout << "Last Input: " << 36 << " Current Input: "<<  0 <<"  Level: "<< static_cast<int>(level) << endl;

    level = hysteresis_level_evaluator(0, threshold);
    cout << "Last Input: " << 0 << "  Current Input: "<<  0 <<"  Level: "<< static_cast<int>(level) << endl;

    return 0;


}


/**
 *[the function takes a vector of strctures that represents the upper and lower levels for ] 
*/
uint8_t hysteresis_level_evaluator(uint8_t current_prcent, vector  < Hys_range*> & threshold )
{
    static uint8_t last_percent = 0;
    static uint8_t last_level   = 0;
    uint8_t level = 0;


    if (current_prcent > 100)
    {
        throw invalid_argument("Value between 0, and 100");
    }
    for(uint8_t i = 0; i<threshold.size(); i++)
    {
        uint8_t mid = (threshold[i]-> upper + threshold[i]-> lower) /2 ; 
        
        #ifdef DEBUG_PRINT
        cout << "last_percent: " << (int)last_percent << " current_percent: " << (int)current_prcent;
        cout <<  " low: " <<  (int)(threshold[i] -> lower) << " hight: " << (int)(threshold[i] -> upper) << endl;
        cout << "MID: " << (int)mid << endl;
        #endif

        if ((last_percent > mid) && (current_prcent <= (threshold[i] -> upper)) &&
             (current_prcent >= (threshold[i] -> lower)))
        {
           
            last_percent = current_prcent;
            if (last_level == threshold[i] -> level)
            {
                return threshold[i] -> level;
            }
        }

        else if (current_prcent > mid)
        {
            level = threshold[i]-> level;
        }        

    } 
    last_percent = current_prcent;
    last_level = level;
    return level;

}
