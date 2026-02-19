class Solution {
public:
    string simplifyPath(string path) {
        deque<string_view> names;
        int lastSlashIndex = 0;

        for (int i = 1; i < path.size(); i++) {
            if (path[i] != '/') continue;

            int length = i - lastSlashIndex - 1;
            if (length > 0) {
                string_view substring(&path[lastSlashIndex + 1], length);

                if (substring == "..") {
                    if (!names.empty()) names.pop_back();
                } else if (substring != ".") names.push_back(substring);
            }
            
            lastSlashIndex = i;
        }

        int length = path.size() - lastSlashIndex - 1;
        if (length > 0) {
            string_view substring(&path[lastSlashIndex + 1], length);

            if (substring == "..") {
                if (!names.empty()) names.pop_back();
            } else if (substring != ".") names.push_back(substring);
        }

        string res = "/";
        while (!names.empty()) {
            res += names.front();
            if (names.size() != 1) res += "/";
            names.pop_front();
        }

        return res;
    }
};