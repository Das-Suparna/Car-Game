#include<graphics.h>

#define carX1 500
#define carX2 580
#define carY1 600
#define carY2 725
#define enemyCarWidth 80

void CreateNMoveEnemyCar(int x, int y, int moveFactor, colors body, colors head)
{
    setcolor(BLACK);
    rectangle(x, y+moveFactor, x+enemyCarWidth, -130+y+moveFactor);
    setfillstyle(SOLID_FILL, body);
    floodfill(x+1, -50+y+moveFactor+1, BLACK);

    setcolor(BLACK);
    rectangle(x+5, y+moveFactor, x+(enemyCarWidth-5), 5+y+moveFactor);
    setfillstyle(SOLID_FILL, head);
    floodfill(x+6, 5+y+moveFactor-1, BLACK);

}

void loading(void){
        
		for(int i=0; i<=450; i++)
		{      setcolor(YELLOW);  
			   settextstyle(BOLD_FONT, 0, 8);
			   outtextxy(600, 100," CAR RACE GAME ");
			   settextstyle(BOLD_FONT, 0, 1);
			   outtextxy(300, 40,"         __________         ");
	 	       outtextxy(300, 70,"    __ /            \\ __   ");
	 	       outtextxy(300, 100,"   '-'/______________\\'-'  ");
	 	       outtextxy(300, 130,"     /    :______:    \\    ");
	 	       outtextxy(300, 160,"    :(()==\\__{}__/==()):   ");
	 	       outtextxy(300, 190,"    | =-(##########)-= |    ");
	 	       outtextxy(300, 220,"    |_|.------------.|_|    ");
	
				  
			   setcolor(LIGHTGREEN);
			   settextstyle(BOLD_FONT, 0, 4);
               outtextxy(500, 300,"     INSTRUCTIONS TO PLAY    ");
             
               setcolor(LIGHTMAGENTA);
               outtextxy(500, 350,"       YOU HAVE 3 LIVES ");
               setcolor(WHITE);
               outtextxy(500, 400,"PRESS -> KEY TO Shift CAR Right ");
               outtextxy(500, 450,"PRESS <- KEY TO Shift CAR Left  ");
              
              
               settextstyle(BOLD_FONT, 0, 3);
               setcolor(CYAN); 
               outtextxy(590, 520,"         LOADING.......  ");
			   line(532+i,572,532+i,618);
			   outtextxy(520, 630,"The moment loading stops Game starts.....   ");
			   delay(10);
		}		
 	cleardevice();  
}

void end_game(void){          
     cleardevice();  
}

int main()
{
	

    int gd = DETECT, gm;
  
	initwindow(2700,1600,"CAR RACE",150,50);
	
	
	loading();
		
    int roadX1 = 500, roadX2 = 1020, roadY1 = -1, roadY2 = 800;
    int roadLineY =- 200;
   

	
    int carX = 0, carSpeed = 20;
    int enemyNormal = 0, enemyFast = 0, enemySlow = 0;

    int point = 0, life = 3;
    char pointBuffer[10] = {'0'};



    while(1)
    {
    
        setactivepage(0);
        setvisualpage(1);
        cleardevice();

        ///Setting the Color of the background
        setcolor(GREEN);
        rectangle(0, 0, 1000, 000);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(1, 1, GREEN);

        ///For road
        setcolor(WHITE);
        rectangle(roadX1, roadY1, roadX2, roadY2);
        setfillstyle(SOLID_FILL, DARKGRAY);  /// Sets the current fill pattern and fill color
        floodfill(roadX1+1, roadY1+1, WHITE);  ///Fill an enclosed area

        ///Lines in road
        
               
        for(int i=0; i<450; i+=105)
        {
            rectangle(roadX1+90, 10+i+roadLineY, roadX2-90, 50+i+roadLineY);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(591, 11+i+roadLineY, WHITE);
        }
       
        
        /// For repeat road lines
        roadLineY += 15;
        if(roadLineY > 500)
            roadLineY = - 500;


        ///For life and points label
        		settextstyle(BOLD_FONT, 0, 5);
                outtextxy(1070, 35,"LIFE:       ");
                outtextxy(1070, 110,"POINTS:     ");
        
		///OUR TEAM MEMBERS
		       
                settextstyle(BOLD_FONT, 0, 4);
                outtextxy(75, 100, "   CREATED BY  ");
                outtextxy(75, 140,"    GROUP - 2  ");
                outtextxy(5, 200,"-------------------------");
                outtextxy(5, 235,"| SUPARNA DAS     22019 |");
                outtextxy(5, 265,"| SAHIL PANCHAAL  22020 |");
                outtextxy(5, 295,"| VIVEK MAURYA    22040 |");
                outtextxy(5, 325,"| AYUSH JOSHI     22043 |");
                outtextxy(5, 355,"-------------------------");
                
                
                
        /// INSTRUCTIONS TO PLAY THE GAME        
                
                
                settextstyle(BOLD_FONT, 0, 4);
                outtextxy(1050, 225,"      INSTRUCTIONS     ");
                outtextxy(1050, 255," PRESS -> KEY TO SHIFT ");
                outtextxy(1050, 285,"          CAR RIGHT    ");
                outtextxy(1050, 315," PRESS <- KEY TO SHIFT ");
                outtextxy(1050, 345,"          CAR LEFT     ");
            
                
        ///Drawing circle for life
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, YELLOW);
        switch(life)
        {
        case 0: 
            ///Exit when life is no longer
            delay(3000);
            exit(0);
        case 1:
           circle(1220, 60, 20);
            floodfill(1221, 61, WHITE);

            break;

        case 2:
            circle(1220, 60, 20);
            floodfill(1221, 61, WHITE);
            circle(1280, 60, 20);
            floodfill(1281, 61, WHITE);
           
            break;

        case 3:
            circle(1220, 60, 20);
            floodfill(1221, 61, WHITE);
            circle(1280, 60, 20);
            floodfill(1281, 61, WHITE);
            circle(1340, 60, 20);
            floodfill(1341, 61, WHITE);
            break;
        }

        ///Display points
        settextstyle(BOLD_FONT, 0, 5);
        outtextxy(1300, 110, pointBuffer);

        ///Body of car
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BROWN);
        rectangle(500+carX, carY1+15, carX2+carX, carY2+5);
        floodfill(501+carX, carY1+16, BLACK);

        setfillstyle(SOLID_FILL, RED);
        rectangle(500+5+carX, carY1+100, (carX2-5)+carX, carY2);
        floodfill(506+carX, carY1+21, BLACK);

        ///Front of car
        setfillstyle(SOLID_FILL, GREEN);
        rectangle(500+5+carX, carY1, (carX2-5)+carX, carY2-55);
        floodfill(506+carX, carY1+1, BLACK);

        ///Car wheels
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(500+5+carX, carY1+7, 90, 270, 6);
        pieslice(500+75+carX, carY1+7, 270, 90, 5);


       ///Enemy car 1
        CreateNMoveEnemyCar(510, -50, enemySlow, YELLOW, GREEN);
        
        if (enemySlow >= (carY1 + 50))
        {
            switch(carX + carX1)
            {
            case (510 - (carX2-carX1)) ... (510 + enemyCarWidth):
                life--;
                delay(1000);
                enemySlow = - 10;
            }
        }
        ///Enemy car 2
        CreateNMoveEnemyCar(700, -100, enemyNormal, BLUE, BROWN);
        if (enemyNormal >= (carY1 + 100))
        {
            switch(carX + carX1)
            {
            case (700 - (carX2-carX1)) ... (700 + enemyCarWidth):
                life--;
                delay(1000);
                enemyNormal = - 10;
            }
        }
        ///Enemy car 3
        CreateNMoveEnemyCar(890, -30, enemyFast, RED, CYAN);
        if (enemyFast >= (carY1 + 30))
        {
            switch(carX + carX1)
            {
            case (890 - (carX2-carX1)) ... (890 + enemyCarWidth):
                life--;
                delay(1000);
                enemyFast = - 10;
            }
        }
              
        enemySlow += 23;
        enemyNormal += 35;
        enemyFast += 38;


        /// For repeat enemy cars
        if (enemyNormal > getmaxy() + 50)
        {
            point += 3;
            itoa(point, pointBuffer, 10);
            enemyNormal = - 100;
        }

        if (enemyFast > getmaxy() + 100)
        {
            point += 5;
            itoa(point, pointBuffer, 10);
            enemyFast = - 30;
        }

        if (enemySlow > getmaxy() + 30)
        {
            point += 1;
            itoa(point, pointBuffer, 10);
            enemySlow = - 50;
        }             

        /// For car movement
        if(GetAsyncKeyState(VK_LEFT))
        {
            if ((carX + carX1) >= roadX1)
                carX -= carSpeed;
        }
        else if(GetAsyncKeyState(VK_RIGHT))
        {
            if ((carX + carX1 + (carX2-carX1)) <= roadX2)
                carX += carSpeed;
        }

        ///Display game over when life is no longer
        if (life == 0)
        {
        	end_game();
        	rectangle(0, 0, 1000, 000);
        	setfillstyle(SOLID_FILL, GREEN);
         	setcolor(WHITE);  
          
        	setcolor(WHITE);
            settextstyle(BOLD_FONT, 0, 7);
            outtextxy(470,300, "  OOPS YOU LOST ");
            outtextxy(470,370, "   THE GAME!!!   "); 
            delay(2000);
        }

        delay(100);
        
        	
    }


	
    closegraph();

    return 0;
}
