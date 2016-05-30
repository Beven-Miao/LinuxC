#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include <nds3/nds.h>
#include <thread>


/**
 * @brief Class that declares and implement a fictional Oscilloscope device.
 *
 * The class does not need to be derived from any special class, but its constructor must
 *  accept few manadatory parameters and should register the root node via Node::initialize().
 */
class Oscilloscope
{
public:
    /**
     * @brief Constructor.
     *
     * @param factory    the control system factory that requested the creation of the device
     * @param device     the name given to the device
     * @param parameters optional parameters passed to the device
     */
    Oscilloscope(nds::Factory& factory, const std::string& device, const nds::namedParameters_t& parameters);

private:
    /**
     * @brief Amplitude of the sinusoidal wave
     */
    nds::PVVariableOut<std::int32_t> m_sinWaveAmplitude;

    /**
     * @brief Amplitude of the square wave
     */
    nds::PVVariableOut<std::int32_t> m_squareWaveAmplitude;

    /**
     * @brief Acquisition node for the sinusoidal wave
     */
    nds::DataAcquisition<std::vector<std::int32_t> > m_acquisitionSinWave;

    /**
     * @brief Acquisition node for the square wave
     */
    nds::DataAcquisition<std::vector<std::int32_t> > m_acquisitionSquareWave;

    void switchOnSinWave();  ///< Called to switch on the sinusoidal wave acquisition node.
    void switchOffSinWave(); ///< Called to switch off the sinusoidal wave acquisition node.
    void startSinWave();     ///< Called to start the data acquisition on the sinusoidal wave node.
    void stopSinWave();      ///< Called to stop the data acquisition on the sinusoidal wave node.
    void recoverSinWave();   ///< Called to recover the sinusoidal wave node from a failure.

    void switchOnSquareWave();  ///< Called to switch on the square wave acquisition node.
    void switchOffSquareWave(); ///< Called to switch off the square wave acquisition node
    void startSquareWave();     ///< Called to start the data acquisition on the square wave node.
    void stopSquareWave();      ///< Called to stop the data acquisition on the square wave node.
    void recoverSquareWave();   ///< Called to recover the square wave node from a failure.

    /**
     * @brief Called to verify if a state change is allowed
     * @return
     */
    bool allowChange(const nds::state_t, const nds::state_t, const nds::state_t);

    /**
     * @brief Function that continuously pushes a sinusoidal wave to m_acquisitionSinWave
     *        until the flag m_bStopAcquisitionSinWave is set to true.
     *
     * It is launched by startSinWave() in a separate thread.
     */
    void acquireSinusoidalWave();

    /**
     * @brief Function that continuously pushes a square wave to m_acquisitionThreadSquareWave
     *        until the flag m_bStopAcquisitionSquareWave is set to true.
     *
     * It is launched by startSinWave() in a separate thread.
     */
    void acquireSquareWave();

    /**
     * @brief A thread that runs acquireSinusoidalWave().
     */
    std::thread m_acquisitionThreadSinWave;

    /**
     * @brief A boolean flag that stop the acquisition loop in acquireSinusoidalWave()
     *        when true.
     */
    volatile bool m_bStopAcquisitionSinWave;

    /**
     * @brief A thread that runs acquireSquareWave().
     */
    std::thread m_acquisitionThreadSquareWave;

    /**
     * @brief A boolean flag that stop the acquisition loop in acquireSquareWave()
     *        when true.
     */
    volatile bool m_bStopAcquisitionSquareWave;
};

#endif // OSCILLOSCOPE_H
