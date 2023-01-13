package cn.cpoet.yunzhi.note.api.feign;

import java.lang.annotation.*;

/**
 * 只能Feign进行调用
 *
 * @author CPoet
 */
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
@Documented
public @interface FeignTarget {
}
