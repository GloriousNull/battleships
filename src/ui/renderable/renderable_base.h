//
// Created by GloriousSir on 12/7/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_BASE_H
#define SRC_BATTLEFIELDS_RENDERABLE_BASE_H


class renderable_base
{
private:
    virtual void render_impl() const = 0;
public:
    void render() const;
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_BASE_H
