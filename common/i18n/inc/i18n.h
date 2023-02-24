#ifndef CC_I18N_H
#define CC_I18N_H

#define tr I18n

namespace cc {
    class I18n {
    private:
        static I18n INSTANCE;

    public:
        static I18n &getInstance();
    };
}

#endif
