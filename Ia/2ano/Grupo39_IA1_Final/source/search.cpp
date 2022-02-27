#include "search.h"

double pheromones[MAX][MAX]={0};

void nearest_Neighbour(Map *m){

    int r =rand()%(m->Points.size()-1);
    
    Point *inicial_Point = m->Points[r];
    Point *final_point;
    
    m->Openlist.push_back(inicial_Point);
    m->Path.push_back(inicial_Point);

    bool goalFound=false;
    
    while(!goalFound){
        Point *current_Point = m->Openlist[0];
        m->Openlist.erase(m->Openlist.begin());
        
        current_Point->visited=true;

        double dist_min=sqrt(pow(m->MaxN*2,2)+pow(m->MaxN*2,2));//diagonal
        Point *next_Point;
        next_Point=current_Point;
        
        for(auto const& i :m->Points){
            
            if(!i->visited){

                int x = i->x - current_Point->x; //calculating number to square in next step
                int y = i->y - current_Point->y;
                double dist;

                dist = pow(x, 2) + pow(y, 2);//calculating Euclidean distance
                dist = sqrt(dist);

                if(dist<=dist_min){
                    dist_min=dist;
                    next_Point=i;
                }
            }
        }

        if(!next_Point->visited){
            m->Openlist.push_back(next_Point);
            m->Path.push_back(next_Point);
        }

        else{
            goalFound=true;
            final_point=next_Point;
        }

    }
    m->Path.push_back(inicial_Point);
    cout << "n de iteracoes nn: " << m->Points.size() << endl;
}

vector<Point*> hill_climbing(char opt, vector<Point*> inicial ){

    vector<Point*> best = inicial;
    vector<vector<Point*>>* candidates = two_exchange(best);

    vector<Point*> neighbour = choose_opt(opt, candidates,best);
    int iteracoes=1;
    while((neighbour.size()>0)){

        iteracoes++;
        double best_per=perimeters(best);
        double neighbour_per=perimeters(neighbour);

        if(neighbour_per<best_per){
            best=neighbour;
            candidates=two_exchange(best);
            neighbour=choose_opt(opt,candidates,best); 
        }
        else{
            break;
        }

    }
     cout << "n de iteracoes hc: " << iteracoes << endl; 
    return best;
}

vector<Point*> simulated_annealing(vector<Point*> inicial){   
    vector<Point*> best = inicial;

    vector<Point*> neighbour = choose_opt('c',two_exchange(inicial),best);
    vector<vector<Point*>>* candidates = two_exchange(best);

    double temp =  (double) n_Intersections(inicial); 
    int iteracoes=1;
    while(temp>DBL_MIN && candidates->size() > 0){
        iteracoes++;
        double best_per=perimeters(best);
        double neighbour_per=perimeters(neighbour);

        if(accept(best_per,neighbour_per,temp)){
            best=neighbour;
            candidates=two_exchange(best);
            neighbour=choose_opt('c',candidates,best);
        }   
        temp*=0.95;     
    }
    cout << "n de iteracoes sa: " << iteracoes << endl; 
    return best;
}

vector<Point*> ant_colony(vector<Point*> Points){
    vector<Point*> solution;
    vector<Point*> ant_path;

    double best_per=DBL_MAX;
    double actual_per=0.0; 
    int size= Points.size();   
    
    int n_iterations=size;
    //numero de iteracoes do ciclo aumentar faz sobrecarga no processador mas o resultado fica mais preciso
    int n_ants=1000*size;

    double ALPHA=0.0;//pheromone
    double BETA =0.750;//distance
    
    double mult=0.0000000000000000001;

    for(int n = 0; n<n_iterations; n++){
        for(int k = 0; k<n_ants; k++)   {    
            for(auto const& i : Points){
                i->visited=false;
            } 
            int p_inicial=k%size;
            Point* actual=Points[p_inicial];
            ant_path.push_back(actual);
            actual->visited=true;
            Point* nextPoint=ant_choose_point(actual,&Points,ALPHA,BETA);
            while(!nextPoint->visited){
                actual=nextPoint;
                ant_path.push_back(actual);
                for(auto const& i : ant_path){
                    i->visited=true;
                }   
                nextPoint=ant_choose_point(actual,&Points,ALPHA,BETA);
            }
            Point* final=Points[p_inicial];
            ant_path.push_back(final); 
            actual_per=perimeters(ant_path);

            if((best_per>actual_per) && (ant_path.size()==size+1)){
                best_per=actual_per;
                solution=ant_path;
            }
            ant_path.clear();
             for(int a=0;a<size;a++){
                for(int b=0;b<size;b++){
                    if(pheromones[a][b]>100){
                        pheromones[a][b]=100;
                    }
                    else
                        pheromones[a][b]=pheromones[a][b]*0.75;
                }
            }
        }
        mult=sqrt(mult);
        ALPHA=ALPHA+(mult);
        if(ALPHA>2){
            ALPHA=2.0;
        }
    }
    int iteracoes = n_ants*n_iterations;
     cout << "n de iteracoes ac: " << iteracoes << endl;
    return solution;
}