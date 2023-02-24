#include "inc/i18n.h"

using namespace cc;

I18n I18n::INSTANCE;

I18n &I18n::getInstance() {
    return I18n::INSTANCE;
}
