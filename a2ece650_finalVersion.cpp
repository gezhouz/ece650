#include <iostream>
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <regex>

using namespace std;
// we need init a graph which is a dictionary contain the edges 

// This class represents a directed graph using 
// adjacency list representation 

class Graph
{
    int V; // No. of the vertices
    //int m_V;
     // Pointer to an array containing adjacency 
    // lists 
    std::list<int> *m_adj; 
    std::map<int,string> m_prev;
    std::vector<int> m_edge_vector;

    public:
        Graph(int V);// constructor
        // function to add an edge to graph
        void addEdge(int v, int w);
        //function to print BFS traversal from a given source s
        void BFS(int s);
        void show();
        void shortest_path(int start, int end);
        void set_V(int set_v);
        int  get_V();
        void set_Edge_vectors(std::vector<int> edge_vectors);
        std::vector<int> get_Edge_vectors();


};

//init Graph with V vertice
Graph::Graph(int V)
{
    this->V = V;
    //m_V = V;
    //this->m_V = V; // like self.V = V
    //create a list with len V
    //m_adj = new list<int>[V]; 
    //cout<<"Graph initialized"<<endl;

}
void Graph:: addEdge(int v,int w)
{
    m_adj[v].push_back(w) ;// add w to v's list ;
    //cout<<"Edge added"<<endl;
    m_adj[w].push_back(v);
    //cout << typeid(*m_adj).name() << endl;

}
 

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    //bool *visited =new bool[V];
    std::vector<int> visited;
    std::map<int,string> BFS_prev;


    //bool *visited 
    //visited = new bool[V]
    // bool *visited =new bool[m_V];
    
    // set visited to all false
    // for (int i = 0;i<V;i++)
    //     visited[i] =false;
    for (int i = 0;i<V;i++)
        visited.push_back(0);
        //cout << typeid(false).name() << endl;
    // create a queue for BFS
    std::list<int> my_queue ;
    // mark the current node as visited and enqueue it
    visited[s] = 1;
    // push_back == append() in python
    my_queue.push_back(s);
    std::list<int>::iterator i ;
    while (!my_queue.empty())
    {
        // Dequeue a vertex from queue and print it
        // get s as the 1st element in queue
        // notice that the pop is from the front all to empty
        // fisrt in first out back in front out 
        s = my_queue.front();
        //print s 
        //std::cout <<"s = "<<s<< endl;
        //pop s
        my_queue.pop_front();
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        // pay attention i is iterartor 
        // i is like a pointer which store the address of the m_adj[s].begin()
        //m_adj[s] store a list of adjs
        for (i =m_adj[s].begin(); i !=m_adj[s].end();++i)
        //for (int x:adj[s]) 

        {
            // if(!visited[*i])
            // {
            //     visited[*i] = true;
            //     //self.prev[i] = s
            //     m_prev[*i] = to_string(s);
            //     my_queue.push_back(*i);
            //     //std::cout<<"i in adj = "<<*i<<endl;
            // }
            if(visited[*i] == 0)
            {
                visited[*i] = 1;
                //self.prev[i] = s
                BFS_prev[*i] = to_string(s);
                my_queue.push_back(*i);
                //std::cout<<"i in adj = "<<*i<<endl;
            }
        }
    }
    m_prev =BFS_prev;
    //delete [] visited;
    //cout<<"BFS FINISHED**************"<<endl;
}
void Graph::show()
{
    // cout<<"Vertice V ="<<V<<endl;
    // std::list<int>::iterator iter_out ;
    // std::list<int>::iterator iter ;
    // for ( int s_v= 0; s_v != V ;++s_v)
    // {   
    //     cout<<"sv=="<< s_v<<endl;
    //     for (iter = m_adj[s_v].begin(); iter != m_adj[s_v].end();++iter)
    //     {
    //         cout<<"elemtns = " << *iter<<endl;
    //     }
    // };
}

void Graph::set_V(int set_v)
{
    V = set_v;
    m_adj = new list<int>[V];
    //cout<<"set_v is working and V is seted = "<<V<<endl;
}

int Graph::get_V()
{
    return V;
}

void Graph::set_Edge_vectors(std::vector<int> edge_vectors)
{
    m_edge_vector = edge_vectors; 
}

std::vector<int> Graph::get_Edge_vectors()
{
    return m_edge_vector;
}


void Graph::shortest_path(int start, int end)
{
    int pathstate = 1;
    std::list<int> path;
    path.push_back(end);
    int i = end;
    //cout<<"shortest_path is working"<<endl;
    while(m_prev[i] != to_string(start) )
    {   
        if(m_prev[i]=="")// if prev[i] not exist means at the end of the chain
            {
                cerr<<"Error:path does not exist"<<endl;
                pathstate = 0;
                //*pathstate.clean();
                break;
            }
        else
            {   
                path.push_front(stoi(m_prev[i]));
                i = stoi(m_prev[i]);
            }
        // path.push_front(stoi(m_prev[i]));
        // i = stoi(m_prev[i]);
    }
    if(pathstate == 1)
    {
        path.push_front(start);
        for (auto var:path)
            {   if (var == path.back())
                    cout<<var<<endl;
                else
                    cout<<var<<"-";
            }
    }
    // path.push_front(start);
    // for (auto var:path)
    // {   if (var == path.back())
    //         cout<<var<<endl;
    //     else
    //         cout<<var<<"-";
    //}
}
//std::string my_input = "V 10";
std::pair<std::string,std::vector<int>> parser(std::string userInput) 
//void parser(std::string userInput)
{ 
    
    string line = userInput; 
    std::pair<std::string,std::vector<int>> return_pair;
    // Vector of string to save tokens 
    vector <string> tokens; 
      
    // stringstream class check1 
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
      
    // Printing the token vector 
    //for(int i = 0; i < tokens.size(); i++) 
        //cout << tokens[i] << '\n';
    // command = V
    if (tokens[0] == "V")
    {   
        //cout<<"v return"<<endl;
        std::string command;
        std::vector<int> return_vector;
        command ="V";
        //cout<<"yes we need V"<<endl;
        int v;
        stringstream(tokens[1])>>v;
        //cout<<"our v = "<<v<<endl; 
        return_vector.push_back(v);
        return_pair = std::make_pair(command,return_vector);
        //cout<<"parser v return "<<endl;
        return return_pair;
        //cout<<"parser v return "<<endl;
    };
    // command = s
    if (tokens[0] == "s")
    {   
        //cout<<"s return"<<endl;
        std::vector<int> return_vector;
        int start , end;
        stringstream(tokens[1])>> start;
        //cout<<"start*2 = "<<start*2<<endl;
        stringstream(tokens[2])>> end;
        //cout<<"end+10 = "<<end+10<<endl;
        return_vector.push_back(start);
        return_vector.push_back(end);
        return_pair = std::make_pair("s",return_vector);
        //cout<<"parser s return"<<endl;
        return return_pair;
        //cout<<"parser s return"<<endl;
    };
    // command = "E"
    if (tokens[0]== "E")
    {       
            std::vector<int> edges;
            std::string subject(userInput);
            //find all the elements match the regex *****************
            try {
                std::regex re("[0-9]+");
                std::sregex_iterator next(subject.begin(), subject.end(), re);
                std::sregex_iterator end;
            while (next != end) 
                {
                std::smatch match = *next;
                //std::cout<<"numbers in E = " << match.str() << "\n";
                edges.push_back(std::stoi( match.str() ));
                next++;
                } 
                } 
                catch (std::regex_error& e) 
                {
  // Syntax error in the regular expression
                }
            //cout<<edges.size();
            // for (int var:edges)
            // {
            // cout<<"numbers in edges = " <<var<<endl;
            // }
            // std::vector<std::pair<int,int>> edges_vector;
            // for(int i=0;i< edges.size();i=i+2)
            // {
            // std::pair<int,int> e_pair =std::make_pair(edges[i],edges[i+1]) ;
            // cout<<edges[i]<<" and "<<edges[i+1]<<endl;
            // edges_vector.push_back(e_pair);
            // };
            // for(auto var:edges_vector)
            // {
                
            //     cout<<" first = "<<var.first<<" second = "<<var.second<<endl;
            // };
            return_pair = std::make_pair("E",edges);
            //cout<<"parser E RETURN"<<endl;
            return return_pair;
    };
    return return_pair = make_pair("invalid command",std::vector<int>{0});
}

// int main()
// {
//     std::string my_input = "E {<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}";

//     auto result = parser(my_input);
//     cout<< result.first<<endl;
//     for (auto var:result.second)
//         {
//             cout<<var<<endl;
//         }
// }
void run(Graph &g,std::string my_input)
{   
    //cout<<"the newst version of p2"<<endl;
    //cout<<"check g.show() now"<<endl;
    //g.show();
    //cout<<"end check"<<endl;
    // int V_state = 0
    // int E_state = 0
    //Graph g(0);
    //std::string my_input = "V 5";
    std::vector<int> Vertice_number; 
    std::vector<int> Edges_vector;
    std::vector<int> shortest_path_vector;

    auto result = parser(my_input);
    auto command = result.first;
    //cout<<command<<" is my cmd*******"<<endl;
    auto numbers = result.second;
    //set vrtice_number = 2
    //Vertice_number = parser("V 2").second;
    // get the edges_vector from input
    //Edges_vector = parser("E {<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}").second;
    if(!((command =="V") || (command =="E") || (command =="s")))
    {
        cerr<<"Error:Invalid command"<<endl;
    }
    else if (command =="V")
    // should delet all the list and init all the things here
    {
        Vertice_number = result.second ;//vertice_number is a vector;
        //cout<<"vertice_number = "<< Vertice_number[0]*10<<endl;
        int v = Vertice_number[0];
        g.set_V(v);
        //cout<<"this g.show() is in the run function"<<endl;
        g.show();
    }
    else if(command == "s")
    {
        shortest_path_vector = result.second;
        std::vector<int> v = g.get_Edge_vectors();
        int x1 = shortest_path_vector[0];
        int x2 = shortest_path_vector[1];
        if((std::find(v.begin(), v.end(), x1) != v.end()) && (std::find(v.begin(), v.end(), x2) != v.end()))
        {
            /* v contains x */
            //cout<<"ALL GOOD go g.shorest"<<endl;
            int start = x1;
            int end =  x2;
            g.BFS(start);
            g.shortest_path(start,end);
        } 
        else 
        {
            /* v does not contain x */
            cerr<<"Error: Vertice dose not exsist"<<endl;
        }

    }
    else if(command == "E")
    {   
        //cout<<"g.show() in C = E -----------------------"<<endl;
        g.show();
        //cout<<"RUN E IS RUNNING"<<endl;
        Edges_vector = result.second;
        g.set_Edge_vectors(Edges_vector);
        int max_Vertice = 0;
        for(int var:Edges_vector)
        {
            if (var>max_Vertice)
            {
            max_Vertice = var;
            //cout<<"var = "<<var<<" max_V= "<<max_Vertice<<endl; 
            }
        }
        //cout<<max_Vertice<<"= max VERTICE IN EDGES"<<endl;

        if (max_Vertice > g.get_V()-1)
        {
            cerr<<"Error :Vertice out of range"<<endl;
            //wait for input V 
        }
        else
        {
            //cout<<"READY TO RUN g.ADDEDGE"<<endl;
            //cout<<"Edges_vector.size() = "<<Edges_vector.size()<<endl;
            //
            for(int i=0;i< Edges_vector.size()-1;(i=i+2))
            {   
                int p1 = Edges_vector[i];
                //cout<<"p1 = "<<p1<<endl;
                int p2 = Edges_vector[i+1];
                //cout<<"p2 = "<<p2<<endl;
                //cout<<"size = "<<Edges_vector.size()<<endl;
                //cout<<"i=" << i<<endl;
                g.addEdge(p1,p2);
                

            }
        
            // for(int point:Edges_vector)
            // {
            //     cout<<"points = "<<point<<endl;

            // }
        }
    }

}

// int main()
// {
//     std::string my_input1 = "V 15";
//     std::string my_input2 = "E {<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}";
//     std::string my_input3 = "s 2 10";
//     // auto result = parser(my_input);
//     // cout<< result.first<<endl;
//     // for (auto var:result.second)
//     //     {
//     //         cout<<var<<endl;
//     //     }
//    // g.shortest_path(2,10);
//     Graph g(0);
//     //g.shortest_path(2,10);
//     run(g,my_input1);
//     cout<<"g.show in main"<<endl;
//     g.show();
//     cout<<"----------------------g.show in main down"<<endl;
//     run(g,my_input2);
//     run(g,my_input3);
//     //g.shortest_path(2,10);
//     return 0;
// }
int main()
{
    Graph g(0);
    int c = 0;
    while(true)
    {
        std::string userInput;
        //cout<<"Enter a string: "<<endl;
        //cout<<"this is your ####"<< c <<"command"<<endl;
        c = c + 1;
        getline(cin,userInput);
        //cout<<"user input ："<< userInput<<endl;
        if(userInput == "q")
        {
            break;
        }
        run(g,userInput);
    }
    return 0;
}