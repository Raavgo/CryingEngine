
#ifdef __linux__
#define __declspec(v)
#endif


namespace Engine {
    __declspec(dllimport) void printWelcome();
}

int main(){
    Engine::printWelcome();
    return 0;
}