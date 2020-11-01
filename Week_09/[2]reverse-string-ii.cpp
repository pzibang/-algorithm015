class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. Ã¿¸ô 2k ¸ö×Ö·ûµÄÇ° k ¸ö×Ö·û½øÐÐ·´×ª
            // 2. Ê£Óà×Ö·ûÐ¡ÓÚ 2k µ«´óÓÚ»òµÈÓÚ k ¸ö£¬Ôò·´×ªÇ° k ¸ö×Ö·û
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            }
            // 3. Ê£Óà×Ö·ûÉÙÓÚ k ¸ö£¬Ôò½«Ê£Óà×Ö·ûÈ«²¿·´×ª¡£
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};
