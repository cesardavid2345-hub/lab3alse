#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> tokens;

public:
    AuthenticationManager(int ttl) {
        timeToLive = ttl;
    }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId) && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto &t : tokens) {
            if (t.second > currentTime) count++;
        }
        return count;
    }
};

int main() {
    AuthenticationManager am(5);

    am.generate("token1", 1);
    am.generate("token2", 2);
    am.renew("token1", 3);

    cout << "Tokens activos: " << am.countUnexpiredTokens(6) << endl;

    return 0;
}