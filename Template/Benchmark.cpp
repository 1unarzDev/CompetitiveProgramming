// benchmark
class Timer {
    public:
        Timer() {
            set_resolution<chrono::microseconds>();
        }     

        Timer& nanoseconds() { 
            set_resolution<chrono::nanoseconds>();
            return *this;
        }

        Timer& microseconds() {
            set_resolution<chrono::microseconds>();
            return *this;
        }

        Timer& milliseconds() {
            set_resolution<chrono::milliseconds>();
            return *this;
        }

        Timer& seconds() {
            set_resolution<chrono::seconds>();
            return *this;
        }

        void start() {
            m_StartTp = chrono::high_resolution_clock::now();    
        }
        
        void stop() {
            m_EndTp = chrono::high_resolution_clock::now();
        }

        ll time() const {
            return getTime();
        }

    private:
        chrono::time_point<chrono::high_resolution_clock> m_StartTp, m_EndTp;
        function<ll()> getTime;
    
        template<typename DurationType>
        Timer& set_resolution() {
            getTime = [this]() -> ll {
                auto start = chrono::time_point_cast<DurationType>(m_StartTp).time_since_epoch().count();
                auto end = chrono::time_point_cast<DurationType>(m_EndTp).time_since_epoch().count();
                return end - start;
            };
            return *this;
        }
};
