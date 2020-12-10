//
// Created by GloriousSir on 12/10/2020.
//

#ifndef SRC_BATTLEFIELDS_WEB_MESSAGE_H
#define SRC_BATTLEFIELDS_WEB_MESSAGE_H

#include <vector>
#include <cstdint>
#include <cstring>

template <typename T> requires (sizeof(T) == 1)
class web_message
{
private:
    std::vector<std::byte> body;
public:
    web_message() = default;
    explicit web_message(T id)
    {
        body.reserve(1);
        std::memcpy(body.data(), &id, 1);
    }

    std::size_t size() const
    {
        return body.size();
    }

    void * data()
    {
        return body.data();
    }

    template<class DATA> requires std::is_standard_layout_v<DATA>
    friend web_message<T>& operator<<(web_message<T> & msg, const DATA & data)
    {
        std::size_t begin = msg.body.size();

        msg.body.resize(msg.body.size() + sizeof(DATA));
        std::memcpy(msg.body.data() + begin, &data, sizeof(DATA));

        return msg;
    }
};


#endif //SRC_BATTLEFIELDS_WEB_MESSAGE_H
