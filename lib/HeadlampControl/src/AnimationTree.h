#include <Arduino.h>
#include <LinkedList.h>
#include "Animation.h"

#ifndef ANIMATION_TREE_H
#define ANIMATION_TREE_H

/**
 * @brief A node on the animation tree
 */
struct AnimationTreeNode
{
public:
    /// @brief The child of this node corresponding to the on input
    AnimationTreeNode *on;
    /// @brief The child of this node corresponding to the off input
    AnimationTreeNode *off;
    /// @brief The animation associated with this node
    Animation *animation;

    /**
     * @brief Construct a new Animation Tree Node object
     *
     * @param on Child node
     * @param off Child node
     * @param animation Animation stored against this node
     */
    AnimationTreeNode(AnimationTreeNode *on, AnimationTreeNode *off, Animation *animation)
        : on(on), off(off), animation(animation)
    {
    }

    /**
     * @brief Construct a new Animation Tree Node object
     *
     * @param animation Animation stored against this node
     */
    AnimationTreeNode(Animation *animation)
        : animation(animation)
    {
    }

    /**
     * @brief Construct a new Animation Tree Node object
     *
     * @param on Child node
     * @param off Child node
     */
    AnimationTreeNode(AnimationTreeNode *on, AnimationTreeNode *off)
        : on(on), off(off)
    {
    }

    /**
     * @brief Construct a new Animation Tree Node object
     *
     */
    AnimationTreeNode()
    {
    }

    /**
     * @brief Destroy the Animation Tree Node object
     * Deletes all child nodes
     */
    ~AnimationTreeNode()
    {
        delete on;
        delete off;
    }

    /**
     * @brief Find the animation on the node with the given traversal path
     *
     * @param path The path to traverse (true is on, false is off)
     * @return Animation*
     */
    Animation *find(LinkedList<bool> *path)
    {
        auto node = this;

        // Navigate down the tree based on the given path
        for (int i = 0; i < path->size(); i++)
        {
            auto item = path->get(i);

            if (item)
                node = node->on;
            else
                node = node->off;

            if (node == nullptr)
                return nullptr;
        }

        return node->animation;
    }
};

#endif