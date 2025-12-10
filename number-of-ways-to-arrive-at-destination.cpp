// https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
struct Solution {
    static constexpr int MAX = std::numeric_limits<int>::max();

    struct Link {
        int x_{0};
        int y_{0};
        int cost_{MAX};
    };

    struct Node {
        int index_{0};
        int cost_{MAX};
        int count_{0};
        std::vector<Link*> link_list_{};
    };

    int countPaths(int V, std::vector<std::vector<int>>& edges) {
        std::vector<Node*> node_list{};
        for (int i=0; i<V; ++i) {
            node_list.push_back(new Node{i});
        }
        std::vector<Link*> link_list{};
        for (const auto& edge : edges) {
            Link* link = new Link{edge[0], edge[1], edge[2]};
            link_list.push_back(link);
            node_list[link->x_]->link_list_.push_back(link);
            node_list[link->y_]->link_list_.push_back(link);
        }
        std::deque<Node*> queue{};
        Node* cursor = nullptr;
        Node* next = nullptr;

        cursor = node_list[0];
        cursor->cost_ = 0;
        cursor->count_ = 1;
        for (const Link* link : cursor->link_list_) {
            next = node_list[link->x_ != cursor->index_ ? link->x_ : link->y_];
            queue.push_back(next);
        }
        while (!queue.empty()) {
            cursor = queue.front();
            queue.pop_front();
            int cost = MAX;
            int count = 0;
            for (const Link* link : cursor->link_list_) {
                next = node_list[link->x_ != cursor->index_ ? link->x_ : link->y_];
                if (next->count_ > 0) {
                    int tmp_cost = next->cost_ + link->cost_;
                    if (cost > tmp_cost) {
                        cost = tmp_cost;
                        count = next->count_;
                    } else if (cost == tmp_cost) {
                        count = count + next->count_;
                    }
                }
            }
            if ((cursor->cost_ > cost) || ((cursor->cost_ == cost) && (cursor->count_ < count))) {
                cursor->cost_ = cost;
                cursor->count_ = count;
                for (const Link* link : cursor->link_list_) {
                    next = node_list[link->x_ != cursor->index_ ? link->x_ : link->y_];
                    queue.push_back(next);
                }
            }
        }
        return node_list[V-1]->count_;
    }
};
