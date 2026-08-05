class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        if (len != goal.length())
            return false;

        uint32_t mask[104] = {0};
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            mask[(c << 2) + (i >> 5)] |= 1U << (i & 31);
        }

        uint32_t state[4] = {0};
        int targ = len - 1;
        int j = targ >> 5;
        int k = targ & 31;

        for (int i = 0; i < len << 1; i++) {
            int c = goal[i % len] - 'a';
            uint32_t s0 = state[0];
            uint32_t s1 = state[1];
            uint32_t s2 = state[2];

            state[3] = ((state[3] << 1) | (s2 >> 31)) & mask[(c << 2) + 3];
            state[2] = ((s2 << 1) | (s1 >> 31)) & mask[(c << 2) + 2];
            state[1] = ((s1 << 1) | (s0 >> 31)) & mask[(c << 2) + 1];
            state[0] = ((s0 << 1) | 1) & mask[c << 2];

            if (state[j] & (1U << k))
                return true;
        }

        return false;
    }
};