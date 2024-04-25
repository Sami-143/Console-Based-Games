void moveplayercharacterdownright()
{  
    char downright = getCharAtxy(malrioX + 12, malrioY + 8 );
    
    if(downright != '*')
    {  
        eraseMalrio();
        malrioX = 62;
        malrioY = 45;
        ();
    }
    else 
    {
        eraseMalrio();
        malrioY= malrioY + 5 ; 
        malrioX= malrioX + 12;
        printMalrio();
    }


}
void moveplayercharacterdownleft()
{  
    char downleft = getCharAtxy(malrioX- 12 , malrioY + 8);
    
     if(downleft != '*')
    { 
        eraseMalrio(malrioX,malrioY);
        printMalrio(malrioX,malrioY);
    }
 else
    {
        eraseMalrio(malrioX,malrioY);
        malrioY= malrioY - 3; 
        malrioX= malrioX - 4;
        printMalrio(malrioX,malrioY);
    }

}

