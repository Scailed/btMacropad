class Key {

    public:
        Key(int rowPin, int colPin, int debounceMs = 100, int buttonHeldMs = 500);
        void begin();
        bool read();
        bool pressed();
        bool released();
        bool held();

    private:
        int _rowPin;
        int _colPin;
        bool _state;
        int _debounceMs;
        int _ignoreNewInputMs;
        int _buttonHeldMs;
        int _buttonHeldWaitForMs;
};